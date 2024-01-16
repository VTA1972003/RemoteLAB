/* REMOTE LAB || Đọc xung encoder và hiển thị lên màn hình LCD */
/* Khi động cơ quay, encoder xuất xung và sử dụng ngắt ngoài của arduino để đọc và hiển thị lên màn hình LCD */
/* Thông số kỹ thuật động cơ và encoder:
 *    Động cơ DC 12V
 *    Hộp số giảm tốc 128:1
 *    Encoder HEDL 5540 https://www.alldatasheet.com/datasheet-pdf/pdf/105536/ETC/HEDL5540A.html
 *    Số xung trên vòng: 500 ppr
 */

const int interrupt = 0; // Khai báo chân ngắt ngoài của encoder
const int phase_a = 2, phase_b = 3; // Khai báo 2 chân xung của encoder
long pulse = 0; // Khai báo biến số xung đếm được

void setup() 
{
  attachInterrupt (interrupt, encoderdongco, RISING ); // Gọi hàm ngắt ngoài

  pinMode(phase_a, INPUT); // Khai báo kiểu chân
  pinMode(phase_b, INPUT);

  Serial.begin(230400); // Mở cổng Serial
}

void loop() // Vòng lặp chính
{
  Serial.println(pulse); // Viết xung đọc được lên serial
}

void encoderdongco() // Hàm con đọc xung encoder
{
  if (digitalRead(phase_b) == HIGH) // Nếu xung B là xung cạnh lên thì giảm xung đếm được và ngược lại
  {
    pulse--;
  }
  else
  {
    pulse++;
  }
}
