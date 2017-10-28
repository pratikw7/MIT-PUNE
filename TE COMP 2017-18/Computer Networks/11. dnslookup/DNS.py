#!/user/bin/env python

import socket

def getIP(d):
    try:
        data = socket.gethostbyname(d)
        ip = repr(data)
        return ip
    except Exception:
        # fail gracefully!
        return False
#
def getIPx(d):
    try:
        data = socket.gethostbyname_ex(d)
        ipx = repr(data[2])
        return ipx
    except Exception:
        # fail gracefully!
        return False
#
def getHost(ip):
    try:
        data = socket.gethostbyaddr(ip)
        host = repr(data[0])
        return host
    except Exception:
        # fail gracefully
        return False
#
def getAlias(d):
    try:
        data = socket.gethostbyname_ex(d)
        alias = repr(data[1])
        #print repr(data)
        return alias
    except Exception:
        # fail gracefully
        return False


x = input("Enter Domain name or IP address: ")


a = getIP(x)
b = getIPx(x)
c = getHost(x)
d = getAlias(x)

print('IP: {}'.format(a))
print('IPx: {}'.format(b))
print('Host: {}'.format(c))
print('Alias: {}'.format(d))

