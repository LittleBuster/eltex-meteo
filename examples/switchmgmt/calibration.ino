#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <DHTesp.h>

#define CFG_LCD_ADDR 0x27
#define CFG_LCD_WDTH 16
#define CFG_LCD_HGHT 2

#define CFG_SCL_PIN D1
#define CFG_SDA_PIN D2
#define CFG_DHT_PIN D3
#define CFG_GAS_PIN A0

static uint8_t tempCel[8] = { B11100,
                              B10100,
                              B11100,
                              B00000,
                              B00000,
                              B00000,
                              B00000 };


LiquidCrystal_I2C lcd(CFG_LCD_ADDR, CFG_LCD_WDTH, CFG_LCD_HGHT);
MQ135 mq135(CFG_GAS_PIN);
DHTesp dht;


void setup()
{
    pinMode(CFG_GAS_PIN, INPUT);
    lcd.begin();
    lcd.createChar(1, tempCel);
    dht.setup(CFG_DHT_PIN, DHTesp::DHT22);
    lcd.backlight();
}

void loop()
{
    float t = dht.getTemperature();
    float h = dht.getHumidity();  
    float rz = mq135.getCorrectedRZero(t, h);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print((int)t);
    lcd.print("\1");
    lcd.setCursor(9, 0);
    lcd.print("Hum:");
    lcd.print((int)h);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Calibrat: ");
    lcd.print(rz);
    delay(10000);
}
