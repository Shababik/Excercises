### HTTP server exercise
"""
Enables users to get the content of files from the server.
"""

from socket import *
from os.path import exists

# Initializing variables
BUFFER = 3000
HTTP_PORT = 80
CONNECTIONS_LIMIT = 5
ANY_ADDRESS = "0.0.0.0"
HTTP_404 = "HTTP/1.0 404 Not Found"
HTTP_200 = "HTTP/1.0 200 Document Follows"

# Receiving server folder location
folder_name = raw_input("Insert folder name: ")
if folder_name[len(folder_name) - 1] == "/":
    folder_name = folder_name[:-1]
print "Server is running from {folder}"\
    .format(folder=folder_name)

# Creating IP socket
server_soc = socket(AF_INET, SOCK_STREAM)

# Binding to any address and limiting connections
server_soc.bind((ANY_ADDRESS, HTTP_PORT))
server_soc.listen(CONNECTIONS_LIMIT)

# Run server until forcefully closed
while True:
    # Accept connection, read and parse request
    (client_soc, client_addr) = server_soc.accept()
    request = client_soc.recv(BUFFER)
    args = request.split(" ")

    # If request is valid
    if len(args) >= 2 and args[0] == "GET":

        # Create absolute file path on server
        path = folder_name + args[1]

        # File is found
        if exists(path):
            file_content = open(path).read()
            # Return file content according to HTTP standard
            client_soc.sendall(
                HTTP_200 + "\n"
                "Content-length: {length}\n\n".format(length=len(file_content))
                + file_content)
        # File not found
        else:
            client_soc.sendall(HTTP_404 + "\n")

    # Shutting and closing client socket
    client_soc.shutdown(SHUT_RDWR)
    client_soc.close()