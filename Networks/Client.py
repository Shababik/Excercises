### SMTP client exercise
"""
Enables users to connect to their provider's SMTP server,
and send an email to another email address.
"""

from socket import *
import sys
import re

# Initializing variables
BUFFER = 3000
SMTP_PORT = 25
VALID_CONNECTION = "220"
VALID_RESPONSE = "250"

try:
    # Creating IP socket
    soc = socket(AF_INET, SOCK_STREAM)

    # receiving source email address and extracting smtp server address
    # regex searching: '@(----.----)' (can be multiple '.')
    source_addr = raw_input("Enter your email address:")
    re_match = re.search(r"@(?=(.+\..+))", source_addr)
    if re_match is not None:
        server_addr = "smtp.{server}".format(server=re_match.group(1))
    else:
        sys.exit("Invalid email address.")

    # Connecting to SMTP server
    soc.connect((server_addr, SMTP_PORT))
    # Checking for valid connection
    if soc.recv(BUFFER)[:3] != VALID_CONNECTION:
        sys.exit("Couldn't connect to the server.")

    # Sending local hostname to SMTP server
    soc.sendall("HELO {hostname}\n"
                .format(hostname=raw_input("Enter hostname:")))
    # Checking for valid response
    if soc.recv(BUFFER)[:3] != VALID_RESPONSE:
        sys.exit("Invalid hostname")

    # Sending source email address
    soc.sendall("MAIL From: " + source_addr + "\n")
    # Checking for valid response
    if soc.recv(BUFFER)[:3] != VALID_RESPONSE:
        sys.exit("Invalid email address")

    # Sending destination email address
    dest_addr = raw_input("Enter destination email address:")
    soc.sendall("RCPT To: {address}"
                .format(address=dest_addr))
    # Checking for valid response
    if soc.recv(BUFFER)[:3] != VALID_RESPONSE:
        sys.exit("Invalid email address")

    # Sending message terminated by ".\n"
    soc.sendall("DATA\n"
                "From: {source}\n"
                "To: {destination}\n"
                "Subject: {subject}\n\n"
                .format(source=source_addr, destination=dest_addr,
                        subject=raw_input("Enter message subject: ")))
    next_line = raw_input("Enter message content. "
                          "To finish, enter \".\" in a single line.\n"
                          "...\t")
    while next_line != ".":
        soc.sendall(next_line + "\n")
        next_line = raw_input("...\t")
    soc.sendall("\n")
    # Checking for valid response
    if soc.recv(BUFFER)[:3] != VALID_RESPONSE:
        sys.exit("The server did not receive your message.")

    # Disconnecting from SMTP server
    soc.sendall("QUIT\n")

    # Shutting and closing socket
    soc.shutdown(SHUT_RDWR)
    soc.close()

except (error, herror, gaierror, timeout) as e:  # exceptions raised by socket methods
    sys.exit("Couldn't perform this action. Error: {}".format(str(e)))
