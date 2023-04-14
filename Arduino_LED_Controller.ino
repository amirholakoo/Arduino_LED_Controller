
const int ledPin = 9;           // LED connected to digital pin 9
const int buttonPin = 2;        // Button connected to digital pin 2
int buttonState = 0;            // Variable to store button state
int ledState = 0;               // Variable to store LED state (0 = OFF, 1 = ON)
int brightness = 0;             // Variable to store LED brightness (0 - 255)

void setup() {
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
  pinMode(buttonPin, INPUT);    // Set the button pin as input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state
  
  if (buttonState == HIGH) {    // If the button is pressed
    delay(50);                  // Debounce delay
    while (digitalRead(buttonPin) == HIGH); // Wait for button release

    ledState = !ledState;       // Toggle the LED state

    if (ledState) {             // If the LED is ON
      for (brightness = 0; brightness <= 255; brightness++) {
        analogWrite(ledPin, brightness); // Gradually increase brightness
        delay(10);
      }
    } else {                    // If the LED is OFF
      for (brightness = 255; brightness >= 0; brightness--) {
        analogWrite(ledPin, brightness); // Gradually decrease brightness
        delay(10);
      }
    }
  }
}
