# 7 digit display pinout
Below is the pinout in order to directly connect a 7 digit display to the Arduino

| Segment Pin  | Arduino Pin |
| :---: | :---: |
| A  | 6  |
| B  | 5  |
| C  | 2  |
| D  | 3  |
| E  | 4  |
| F  | 7  |
| G  | 8  |
| DP  | 9  |
| C | GND (if common cathode)  |

# Programming
We’ll use a library called SevSeg to control the display. 
The SevSeg library works with single digit and multi-digit seven segment displays.
To install it, open the Arduino IDE, go to: Sketch > Include Library > Add .ZIP Library then select the SevSeg ZIP file that you downloaded.
