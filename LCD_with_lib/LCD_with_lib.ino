
#include <Wire.h> // Khai báo thư viện I2C
#include <LiquidCrystal_I2C.h> // Khai bao thư viện LCD

LiquidCrystal_I2C lcd(0x27,20,4); // Khai báo địa chỉ, kích thước màn hình LCD

int x;

void setup() 
{
  lcd.init(); // Gọi lệnh từ thư viện màn hinh LCD
  lcd.backlight(); // Bật đèn nền của LCD
  lcd.begin(20, 4); // Khởi tạo màn hinh LCD
  lcd.setCursor(0,1);lcd.print("Lac Hong University");
  lcd.setCursor(6,2);lcd.print("RemoteLab");
}

void loop() 
{
  lcd.setCursor(0,3);
  lcd.print(String(x) + " ");
}
