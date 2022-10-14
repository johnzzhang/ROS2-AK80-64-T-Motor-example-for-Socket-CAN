The CAN timeout seems to be 

can_frame_fmt_recv = "=IB3x6s"

= byte order is native
I signed int 4 bytes
B3 unsigned char 3 bytes
x empty 1 byte

Data
6s char 6 bytes

8 header + 6 data = 14 bytes in total