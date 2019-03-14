# Read data from RFID reader

It is possible to use RFID card reader (which is only in keyboard mode!) is such way that it will not interfere with other applications.
A proof of concept C source code opens event handler such as `/dev/input/event6` and then claims exclusive access for this device.
The result is that only this program is able to read from this event. Subsequent requests from other application fail.

Thus we have full control over the RFID reader and can do with the captured data what we want (store it in file, send them to pipe, send them to database, etc...)

# Example Usage
```sh
make
./read_from_event /dev/input/event6

# scan a card and watch as it does not sent keystrokes to tty or X
```
