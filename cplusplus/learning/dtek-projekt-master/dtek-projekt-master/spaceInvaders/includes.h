
void display_init(void);
void delay(int);

extern uint8_t displayArray[128*4];

uint8_t spi_send_recv(uint8_t data);

int getbtns(void);
int getsw(void);

void enable_interrupt(void);

void render(uint8_t arr[]);
void addPixel(int x, int y);
void resetDisplay(void);

void drawLose(void);
void drawWin(void);
void drawStart(void);
