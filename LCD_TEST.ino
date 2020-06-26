// LCD TEST PROGRAM 
// 

#include <LiquidCrystal_I2C.h>
const int LCD_COLUMNS = 20;
const int LCD_ROWS = 4;
int c = 0;
int r = 0;
int cnt = 0;


LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.begin(LCD_COLUMNS, LCD_ROWS);

  Serial.println("Start");
  lcd.setCursor(1, 1);
  lcd.print("hello.");
}

void loop() {
  Serial.print(c);
  Serial.print(",");
  Serial.print(r);
  Serial.print(" --- ");
  Serial.println( cnt ) ;

  lcd.setCursor(c, r);
  lcd.print(char(cnt));

  cnt++;
  c++;
  if ( c >= LCD_COLUMNS ) {
    c = 0;
    r++;
    if ( r >= LCD_ROWS) {
      r = 0;
    }
  }


  delay(100);
}
