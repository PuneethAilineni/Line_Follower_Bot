# Line_Follower_Bot
The code implements a line-following robot using 5 sensors and a PID controller. It reads sensor values to detect the line position, calculates the error, and uses proportional, derivative, and integral terms to determine the motor output. The bot follows a black line by maintaining a desired position using proportional, derivative, and integral terms.
The left most sensor and the right most sensor contributes more to the error because it should turn more, where as the left and right sensor should contribute less to error compared to corner sensors.
Kp,Ki,Kd values are finalised by experimenting the bot.
