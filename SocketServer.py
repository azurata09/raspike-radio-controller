import socket
import time

def handle_client(client_socket):
    try:
        while True:
            response = "1"
            client_socket.send(response.encode('utf-8'))
            time.sleep(1)  # 1秒間隔で送信
    except (ConnectionResetError, BrokenPipeError):
        print("Connection closed by client")
    finally:
        client_socket.close()

def start_server(host='localhost', port=12345):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)
    print(f"Server started on {host}:{port}")
    print("Waiting for connections...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        handle_client(client_socket)

if __name__ == "__main__":
    start_server()