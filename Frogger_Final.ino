#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

const int NUM_VEHICLES = 5;

// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;
const int BUTTON_PIN_NUMBER2 = 12;

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// the following functions are for printing messages
void print_level(int level);
void print_lives(int lives);
void game_over();

class Color {
  public:
    int red;
    int green;
    int blue;
    Color() {
      red = 0;
      green = 0;
      blue = 0;
    }
    Color(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }
    uint16_t to_333() const {
      return matrix.Color333(red, green, blue);
    }
};

const Color BLACK(0, 0, 0);
const Color RED(7, 0, 0);
const Color ORANGE(7, 4, 0);
const Color YELLOW(7, 7, 0);
const Color GREEN(0, 7, 0);
const Color BLUE(0, 0, 7);
const Color PURPLE(7, 0, 7);
const Color WHITE(7, 7, 7);
const Color LIME(4, 7, 0);
const Color AQUA(0, 7, 7);
const Color GRAY(4, 4, 4);


class Frog {
  public:
    Frog() {
      x = 0;
      y = 14;
      lives = 3;
    }
    Frog(int x_arg, int y_arg) {
      x = x_arg;
      y = y_arg;
    }

    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_lives() const {
      return lives;
    }


    void set_x(int x_arg) {
      x = x_arg;
    }
    void set_y(int y_arg) {
      y = y_arg;
    }
    void die() {
      lives = lives - 1;
    }


    void move() {
      y = y - 1;
    }

    void draw() {
      draw_with_rgb(RED, GREEN);
    }

    void erase() {
      draw_with_rgb(BLACK, BLACK);
    }

  private:
     int x;
     int y;
     int lives;

     void draw_with_rgb(Color eye_color, Color body_color) {
        matrix.drawPixel(x, y, eye_color.to_333());
        matrix.drawPixel(x + 1, y, eye_color.to_333());
        matrix.drawPixel(x, y + 1, body_color.to_333());
        matrix.drawPixel(x + 1, y + 1, body_color.to_333());
     }

};

class Car1 {
  public:
    Car1() {
      x = 0;
      y = 0;
      speed = 0;
    }

    Car1(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    void initialize(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_speed() const {
      return speed;
    }

    void move() {
      x = x + 1;
    }

    void draw() {
      switch (speed) {
        case 1:
        draw_with_rgb(BLUE);
        break;
        case 2:
        draw_with_rgb(YELLOW);
        break;
        case 3:
        draw_with_rgb(ORANGE);
        break;
        case 4:
        draw_with_rgb(PURPLE);
        break;
        case 5:
        draw_with_rgb(WHITE);
        break;
        case 10:
        draw_with_rgb(WHITE);
        break;
        default:
        draw_with_rgb(BLACK);
        break;
      }
    }

    void erase() {
        draw_with_rgb(BLACK);
    }

  private:
    int x;
    int y;
    int speed;

    void draw_with_rgb(Color color) {
        matrix.drawPixel(x, y, color.to_333());
        matrix.drawPixel(x - 1, y, color.to_333());
        matrix.drawPixel(x - 2, y, color.to_333());
        matrix.drawPixel(x, y + 1, color.to_333());
        matrix.drawPixel(x - 1, y + 1, color.to_333());
        matrix.drawPixel(x - 2, y + 1, color.to_333());
    }
};

class Car2 {
  public:
    Car2() {
      x = 15;
      y = 0;
      speed = 0;
    }

    Car2(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    void initialize(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_speed() const {
      return speed;
    }

    void move() {
      x = x - 1;
    }

    void draw() {
      switch (speed) {
        case 1:
        draw_with_rgb(BLUE);
        break;
        case 2:
        draw_with_rgb(YELLOW);
        break;
        case 3:
        draw_with_rgb(ORANGE);
        break;
        case 4:
        draw_with_rgb(PURPLE);
        break;
        case 5:
        draw_with_rgb(WHITE);
        break;
        case 10:
        draw_with_rgb(WHITE);
        break;
        default:
        draw_with_rgb(BLACK);
        break;
      }
    }

    void erase() {
      draw_with_rgb(BLACK);
    }

  private:
    int x;
    int y;
    int speed;

    void draw_with_rgb(Color color) {
      matrix.drawPixel(x, y, color.to_333());
      matrix.drawPixel(x + 1, y, color.to_333());
      matrix.drawPixel(x + 2, y, color.to_333());
      matrix.drawPixel(x, y + 1, color.to_333());
      matrix.drawPixel(x + 1, y + 1, color.to_333());
      matrix.drawPixel(x + 2, y + 1, color.to_333());
    }
};

class Truck1 {
  public:
    Truck1() {
      x = 0;
      y = 0;
      speed = 0;
    }

    Truck1(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    void initialize(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_speed() const {
      return speed;
    }

    void move() {
      x = x + 1;
    }

    void draw() {
      switch (speed) {
        case 1:
        draw_with_rgb(BLUE);
        break;
        case 2:
        draw_with_rgb(YELLOW);
        break;
        case 3:
        draw_with_rgb(ORANGE);
        break;
        case 4:
        draw_with_rgb(PURPLE);
        break;
        case 5:
        draw_with_rgb(WHITE);
        break;
        case 10:
        draw_with_rgb(WHITE);
        break;
        default:
        draw_with_rgb(BLACK);
        break;
      }
    }

    void erase() {
        draw_with_rgb(BLACK);
    }

  private:
    int x;
    int y;
    int speed;

    void draw_with_rgb(Color color) {
        matrix.drawPixel(x, y, color.to_333());
        matrix.drawPixel(x - 1, y, color.to_333());
        matrix.drawPixel(x - 2, y, color.to_333());
        matrix.drawPixel(x - 3, y, color.to_333());
        matrix.drawPixel(x, y + 1, color.to_333());
        matrix.drawPixel(x - 1, y + 1, color.to_333());
        matrix.drawPixel(x - 2, y + 1, color.to_333());
        matrix.drawPixel(x - 3, y + 1, color.to_333());
    }
};

class Truck2 {
  public:
    Truck2() {
      x = 0;
      y = 0;
      speed = 0;
    }

    Truck2(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    void initialize(int x_arg, int y_arg, int speed_arg) {
      x = x_arg;
      y = y_arg;
      speed = speed_arg;
    }

    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_speed() const {
      return speed;
    }

    void move() {
      x = x - 1;
    }

    void draw() {
      switch (speed) {
        case 1:
        draw_with_rgb(BLUE);
        break;
        case 2:
        draw_with_rgb(YELLOW);
        break;
        case 3:
        draw_with_rgb(ORANGE);
        break;
        case 4:
        draw_with_rgb(PURPLE);
        break;
        case 5:
        draw_with_rgb(WHITE);
        break;
        case 10:
        draw_with_rgb(WHITE);
        break;
        default:
        draw_with_rgb(BLACK);
        break;
      }
    }

    void erase() {
      draw_with_rgb(BLACK);
    }

  private:
    int x;
    int y;
    int speed;

    void draw_with_rgb(Color color) {
      matrix.drawPixel(x, y, color.to_333());
      matrix.drawPixel(x + 1, y, color.to_333());
      matrix.drawPixel(x + 2, y, color.to_333());
      matrix.drawPixel(x + 3, y, color.to_333());
      matrix.drawPixel(x, y + 1, color.to_333());
      matrix.drawPixel(x + 1, y + 1, color.to_333());
      matrix.drawPixel(x + 2, y + 1, color.to_333());
      matrix.drawPixel(x + 3, y + 1, color.to_333());
    }
};

class Frogger {
  public:
    Frogger() {
      level = 0;
      time = 0;
    }
    void setup(bool button_pressed) {
      level = 8;
      frog = Frog();
      print_level(level);
      print_lives(frog.get_lives());
      reset_level();
      frog.draw();
      for (int i = 0; i < NUM_VEHICLES; i++) {
        carRight[i].initialize(i * 7, 2, 10);
        carLeft[i].initialize(i * 7, 9, 10);
        truckRight[i].initialize(i * -12, 12, 5);
        truckLeft[i].initialize(i * 12 + 32, 5, 5);
      }
      
      
      
     
    }
    void loop(int potentiometer_value, bool button_pressed) {
      unsigned long millis_time = millis();
      draw_frog(potentiometer_value/32, button_pressed);
      draw_car1(millis_time);
      draw_car2(millis_time);
      draw_water();
      frog_in_water();
      car_hits_frog();
      yellow_lines();
      level_set();
      draw_truck1(millis_time);
      draw_truck2(millis_time);
      
      
      
      
    }
  private:
    int level;
    int time;
    Frog frog;
    Car1 carRight[NUM_VEHICLES];
    Car2 carLeft[NUM_VEHICLES];
    Truck1 truckRight[NUM_VEHICLES];
    Truck2 truckLeft[NUM_VEHICLES];
    unsigned long carRight_time = 0;
    unsigned long carLeft_time = 0;
    unsigned long truckRight_time = 0;
    unsigned long truckLeft_time = 0;
    
    bool level_cleared() {
      if (frog.get_y() == 0) {
        return true;
      }
      else {
        return false;
      }
    }
    
    void reset_level() {
      
    }

    void level_set() {
      int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
      
      if (level_cleared()) {
        level++;
        print_level(level);
        print_lives(frog.get_lives());
        reset_level();
        for (int i = 0; i < NUM_VEHICLES; i++) {
          carLeft[i].draw();
        }
        frog.erase();
        frog = Frog(potentiometer_value/32, 14);
        frog.draw();
      }
    }
    
    void player_dies() {
        int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
        
        if (frog.get_lives() < 0) {
        game_over();
      }
        else {
        print_level(level);
        print_lives(frog.get_lives());
        reset_level();
        for (int i = 0; i < NUM_VEHICLES; i++) {
          carLeft[i].draw();
        }
        frog.erase();
        frog = Frog(potentiometer_value/32, 14);
        frog.draw();
        }
     }
    
    void draw_frog(int potentiometer_value, bool button_pressed) {
      frog.erase();
      frog.set_x(potentiometer_value);
      frog.draw();
      if (button_pressed) {
        frog.erase();
        frog.move();
        delay(200);
        frog.draw();
      }
    }
    
    void draw_car1(unsigned long millis_time) {
      if (millis_time - carRight_time > (3000 / carRight[1].get_speed())) {
        for (int i = 0; i < NUM_VEHICLES; i++) {
          if (carRight[i].get_x() >=  34) {
              carRight[i].initialize(-1, 2, 10);
            }
          carRight[i].erase();
          carRight[i].move();
          carRight[i].draw();
          carRight_time = millis_time;
        }
      }
    }
    
    void draw_car2(unsigned long millis_time) {
      if (millis_time - carLeft_time > (3000 / carRight[1].get_speed())) {
        for (int i = 0; i < NUM_VEHICLES; i++) {
          if (carLeft[i].get_x() <=  -3) {
              carLeft[i].initialize(32, 9, 10);
            }
          carLeft[i].erase();
          carLeft[i].move();
          carLeft[i].draw();
          carLeft_time = millis_time;
        }
      }
    }
    
    void draw_truck1(unsigned long millis_time) {
      if (millis_time - truckRight_time > (3000 / truckRight[1].get_speed())) {
        for (int i = 0; i < NUM_VEHICLES; i++) {
          truckRight[i].erase();
          truckRight[i].move();
          truckRight[i].draw();
          truckRight_time = millis_time;
        }
      }
    }
    
    void draw_truck2(unsigned long millis_time) {
      if (millis_time - truckLeft_time > (3000 / truckLeft[1].get_speed())) {
        for (int i = 0; i < NUM_VEHICLES; i++) {
          truckLeft[i].erase();
          truckLeft[i].move();
          truckLeft[i].draw();
          truckLeft_time = millis_time;
        }
      }
    }
    
    void draw_water() {
      switch (level) {
        case 6:
        case 7:
        for (int i = 7; i < 9; i++) {
          for (int j = 0; j < 12; j++) {
            matrix.drawPixel(j, i, AQUA.to_333());
          }
          for (int j = 20; j < 32; j++) {
            matrix.drawPixel(j, i, AQUA.to_333());
          }
        }
        break;
        case 8:
        for (int i = 7; i < 9; i++) {
          for (int j = 2; j < 7; j++) {
            matrix.drawPixel(j, i, AQUA.to_333());
          }
          for (int j = 9; j < 23; j++) {
            matrix.drawPixel(j, i, AQUA.to_333());
          }
          for (int j = 25; j < 30; j++) {
            matrix.drawPixel(j, i, AQUA.to_333());
          }
        }
      }
    }
    
    void frog_in_water() {
      switch (level) {
        case 6:
        case 7:
        if (frog.get_y() > 5 && frog.get_y() < 9) {
          if (frog.get_x() <= 11 || frog.get_x() >= 19) {
            frog.die();
            player_dies();
          }
        }
        break;
        case 8:
        if (frog.get_y() > 5 && frog.get_y() < 9) {
          if (frog.get_x() == 1 || frog.get_x() == 2
               || frog.get_x() == 6 || frog.get_x() == 8
               || frog.get_x() == 24 || frog.get_x() == 22
               || frog.get_x() == 29) {
                frog.die();
                player_dies();
               }
          else if ((frog.get_x() >= 2 && frog.get_x() <= 6) || (frog.get_x() >= 9 && frog.get_x() <= 22) || (frog.get_x() >= 25 && frog.get_x() <= 29)) {
                frog.die();
                player_dies();
        }
        }
        break;
      }
    }
    
    void car_hits_frog() {
      for (int i = 0; i < NUM_VEHICLES; i++) {
        if ((frog.get_x() - carRight[i].get_x() == 0 || carRight[i].get_x() - frog.get_x() == 1 || carRight[i].get_x() - frog.get_x() == 2 || carRight[i].get_x() - frog.get_x() == 3) 
            && (frog.get_y() - carRight[i].get_y() >= -1 && frog.get_y() - carRight[i].get_y() <= 1)) {
          frog.die();
          player_dies();
        }
        else if ((frog.get_x() - carLeft[i].get_x() == 0 || carLeft[i].get_x() - frog.get_x() == 1 || carLeft[i].get_x() - frog.get_x() == -1 || carLeft[i].get_x() - frog.get_x() == -2) 
            && (frog.get_y() - carLeft[i].get_y() >= -1 && frog.get_y() - carLeft[i].get_y() <= 1)) {
          frog.die();
          player_dies();
        }
      }
    }
    
    void truck_hits_frog() {
      for (int i = 0; i < NUM_VEHICLES; i++) {
        if ((frog.get_x() - truckRight[i].get_x() == 0 || truckRight[i].get_x() - frog.get_x() == 1 || truckRight[i].get_x() - frog.get_x() == 2 || truckRight[i].get_x() - frog.get_x() == 3) 
            && (frog.get_y() - truckRight[i].get_y() >= -1 && frog.get_y() - truckRight[i].get_y() <= 1)) {
          frog.die();
          player_dies();
        }
        else if ((frog.get_x() - truckLeft[i].get_x() == 0 || truckLeft[i].get_x() - frog.get_x() == 1 || truckLeft[i].get_x() - frog.get_x() == -1 || truckLeft[i].get_x() - frog.get_x() == -2) 
            && (frog.get_y() - truckLeft[i].get_y() >= -1 && frog.get_y() - truckLeft[i].get_y() <= 1)) {
          frog.die();
          player_dies();
        }
      }
    }
    
    void yellow_lines() {
      for (int i = 0; i < 32; i+=2) {
        matrix.drawPixel(i, 4, YELLOW.to_333());
      }
      for (int i = 0; i < 32; i+=2) {
        matrix.drawPixel(i, 11, YELLOW.to_333());
      }
    }
    
};

Frogger frogger;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  pinMode(BUTTON_PIN_NUMBER2, INPUT);
  matrix.begin();
  bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);
  frogger.setup(button_pressed);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);
  bool button_Frogger = (digitalRead(BUTTON_PIN_NUMBER2) == HIGH);
  frogger.loop(potentiometer_value, button_pressed);

}

// displays Level
void print_level(int level) {
  matrix.fillScreen(BLACK.to_333());
  matrix.setTextColor(GREEN.to_333());
  matrix.setTextSize(1);
  matrix.setCursor(1, 0);
  matrix.print("LEVEL");
  matrix.setCursor(13, 8);
  matrix.print(level);
  delay(3000);
  matrix.fillScreen(BLACK.to_333());
}

// displays number of lives
void print_lives(int lives) {
  matrix.fillScreen(BLACK.to_333());
  matrix.setTextColor(GREEN.to_333());
  matrix.setTextSize(1);
  matrix.setCursor(1, 0);
  matrix.print("LIVES");
  matrix.setCursor(13, 8);
  matrix.print(lives);
  delay(3000);
  matrix.fillScreen(BLACK.to_333());
}

// displays "game over"
void game_over() {
  matrix.fillScreen(BLACK.to_333());
  matrix.setTextColor(GREEN.to_333());
  matrix.setTextSize(1);
  matrix.setCursor(4, 0);
  matrix.print("GAME");
  matrix.setCursor(4, 8);
  matrix.print("OVER");
  delay(10000000);
  matrix.fillScreen(BLACK.to_333());
}
