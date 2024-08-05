import re

with open("auburn.osm", "rb") as file:
    d = file.read()

filtered = re.findall(rb'(?<=lat="|lon=")([0-9\.\-]+)(?=")', d)
with open("output.bin", "wb") as file:
    for i, coord in enumerate(filtered):
        file.write(coord + b" ")
        

