import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
trig_pin = 18
echo_pin = 24

GPIO.setup(trig_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)


def send_trigger_pulse():
    GPIO.output(trig_pin, True)
    time.sleep(0.00001)
    GPIO.output(trig_pin, False)


def wait_for_echo(value, timeout):
    count = timeout
    while GPIO.input(echo_pin) != value and count > 0:
        count -= 1


def get_distance():
    send_trigger_pulse()
    wait_for_echo(True, 10000)
    start_time = time.time()
    wait_for_echo(False, 10000)
    end_time = time.time()
    pulse_duration = end_time - start_time
    distance = pulse_duration * 17150
    distance = round(distance, 2)
    return distance


try:
    while True:
        distance = get_distance()
        print(f"Distance: {distance} cm")
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
