#include <Flash.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

#define buzzer 11
#define buttonStop 9
#define buttonPrev 10
#define buttonNext 8

#define NB0  31
#define NC1  33
#define NCS1 35
#define ND1  37
#define NDS1 39
#define NE1  41
#define NF1  44
#define NFS1 46
#define NG1  49
#define NGS1 52
#define NA1  55
#define NAS1 58
#define NB1  62
#define NC2  65
#define NCS2 69
#define ND2  73
#define NDS2 78
#define NE2  82
#define NF2  87
#define NFS2 93
#define NG2  98
#define NGS2 104
#define NA2  110
#define NAS2 117
#define NB2  123
#define NC3  131
#define NCS3 139
#define ND3  147
#define NDS3 156
#define NE3  165
#define NF3  175
#define NFS3 185
#define NG3  196
#define NGS3 208
#define NA3  220
#define NAS3 233
#define NB3  247
#define NC4  262
#define NCS4 277
#define ND4  294
#define NDS4 311
#define NE4  330
#define NF4  349
#define NFS4 370
#define NG4  392
#define NGS4 415
#define NA4  440
#define NAS4 466
#define NB4  494
#define NC5  523
#define NCS5 554
#define ND5  587
#define NDS5 622
#define NE5  659
#define NF5  698
#define NFS5 740
#define NG5  784
#define NGS5 831
#define NA5  880
#define NAS5 932
#define NB5  988
#define NC6  1047
#define NCS6 1109
#define ND6  1175
#define NDS6 1245
#define NE6  1319
#define NF6  1397
#define NFS6 1480
#define NG6  1568
#define NGS6 1661
#define NA6  1760
#define NAS6 1865
#define NB6  1976
#define NC7  2093
#define NCS7 2217
#define ND7  2349
#define NDS7 2489
#define NE7  2637
#define NF7  2794
#define NFS7 2960
#define NG7  3136
#define NGS7 3322
#define NA7  3520
#define NAS7 3729
#define NB7  3951
#define NC8  4186
#define NCS8 4435
#define ND8  4699
#define NDS8 4978

int size = 0;

int melody[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

FLASH_TABLE(int, melodies, 170, 
    //1. Deck the Hall
    {NC5,NB4,NA4,NG4,NF4,NG4,NA4,NF4,NG4,NA4,NB4,NG4,NA4,NG4,NF4,NE4,NF4,NC5,NB4,NA4,NG4,NF4,NG4,NA4,NF4,NG4,NA4,NB4,NG4,NA4,NG4,NF4,NE4,NF4,NG4,NA4,NB4,NG4,NA4,NB4,NC5,NG4,NA4,NB4,NC5,ND5,NE5,NF5,NE5,ND5,NC5,NC5,NB4,NA4,NG4,NF4,NG4,NA4,NF4,ND5,ND5,ND5,ND5,NC5,NB4,NA4,NG4,NF4},
    {4,8,4,4,4,4,4,4,8,8,8,8,4,8,4,4,2,4,8,4,4,4,4,4,4,8,8,8,8,4,8,4,4,2,4,8,4,4,4,8,4,4,8,8,4,8,8,4,4,4,2,4,8,4,4,4,4,4,4,8,8,8,8,4,8,4,4,2},
          
    //2. Jingle Bell
    {NG4,NE5,ND5,NC5,NG4,NG4,NE5,ND5,NC5,NA4,NA4,NF5,NE5,ND5,NB4,NG5,NG5,NF5,ND5,NE5,NG4,NE5,ND5,NC5,NG4,NG4,NE5,ND5,NC5,NA4,NA4,NF5,NE5,ND5,NG5,NG5,NG5,NG5,NG5,NA5,NG5,NF5,ND5,NC5,NG5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NG5,NC5,ND5,NE5,NF5,NF5,NF5,NF5,NF5,NF5,NE5,NE5,NE5,NE5,NE5,ND5,ND5,NE5,ND5,NG5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NG5,NC5,ND5,NE5,NF5,NF5,NF5,NF5,NF5,NF5,NE5,NE5,NE5,NE5,NG5,NG5,NF5,ND5,NC5},
    {8,8,8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,8,8,2,8,8,8,8,8,8,8,16,16,8,8,8,8,4,4,8,8,4,8,8,4,8,8,8,8,2,8,8,8,16,16,8,8,8,16,16,8,8,8,8,4,4,8,8,4,8,8,4,8,8,8,8,2,8,8,8,16,16,8,8,8,16,16,8,8,8,8,2},
          
    //3. We Wish You A Merry Christmas
    {NG4,NC5,NC5,ND5,NC5,NB4,NA4,NA4,NA4,ND5,ND5,NE5,ND5,NC5,NB4,NG4,NG4,NE5,NE5,NF5,NE5,ND5,NC5,NA5,NG4,NG4,NA4,ND5,NB4,NC5,NG4,NC5,NC5,ND5,NC5,NB4,NA4,NA4,NA4,ND5,ND5,NE5,ND5,NC5,NB4,NG4,NG4,NE5,NE5,NF5,NE5,ND5,NC5,NA5,NG4,NG4,NA4,ND5,NB4,NC5,NG4,NC5,NC5,NC5,NB4,NB4,NC5,NB4,NA4,NG4,ND5,NE5,ND5,ND5,NC5,NC5,NG5,NG4,NG4,NG4,NA4,ND5,NB4,NC5},
    {4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,8,8,4,4,4,2,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,8,8,4,4,4,2,4,4,4,4,2,4,4,4,4,2,4,4,8,8,8,8,4,4,8,8,4,4,4,2},
          
    //4. Gong Xi Gong Xi
    {NA3,NB3,NC4,ND4,NF4,NE4,NE4,NA4,NA4,NE4,NE4,ND4,ND4,NF4,NE4,ND4,ND4,NC4,NC4,NB3,NA3,NGS3,NA3,NA3,ND4,0,NE4,NC4,0,NE4,NB3,NE4,NA3,NE4,ND4,0,NE4,NC4,0,NE4,NB3,NE4,NA3,NA3,NB3,NC4,ND4,NF4,NE4,NE4,NA4,NA4,NE4,NE4,ND4,ND4,NF4,NE4,ND4,ND4,NC4,NC4,NB3,NA3,NGS3,NA3,NA3,ND4,0,NE4,NC4,0,NE4,NB3,NE4,NA3,NE4,ND4,0,NE4,NC4,0,NE4,NB3,NE4,NA3},
    {4,4,4,4,2,2,4,4,4,4,2,2,4,4,4,4,2,2,4,4,4,4,2,2,4,8,8,4,8,8,4,4,4,4,4,8,8,4,8,8,4,4,2,4,4,4,4,2,2,4,4,4,4,2,2,4,4,4,4,2,2,4,4,4,4,2,2,4,8,8,4,8,8,4,4,4,4,4,8,8,4,8,8,4,4,2},
          
    //5. Gangnam Style
    {NA4,NA4,NC5,0,NA4,0,NE5,NE5,NE5,0,ND5,0,ND5,ND5,NE5,0,0,NE5,NE5,NE5,NE5,0,0,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,NE5,0,0,NA4,NA4,NC5,NC5,NA4,0,0},
    {8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,8,4,8,8,8,4,8,4,8,8,8,8,8,8,8,8,8,8,8,4,4,4,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,1,4,8,8,8,8,4,1,4},
          
    //6. Gentleman
    {NB5,0,NB5,0,NB5,NA5,NB5,NB5,NB5,NB5,NB5,NB5,NC6,NB5,NA5,NB5,0,NB5,0,NB5,NA5,NFS5,NFS5,NFS5,NG5,NG5,NG5,NGS5,NGS5,NGS5,NA5,NAS5,NB5,0,NB5,0,NB5,NA5,NB5,NB5,NB5,NB5,NB5,NB5,NC6,NB5,NA5,NB5,0,NB5,0,NB5,NA5,NFS5,NFS5,NFS5,NG5,NG5,NG5,NGS5,NGS5,NGS5,NA5,NAS5},
    {8,4,8,4,8,8,8,16,16,8,8,8,8,8,8,8,4,8,4,8,8,8,16,16,8,16,16,8,16,16,8,8,8,4,8,4,8,8,8,16,16,8,8,8,8,8,8,8,4,8,4,8,8,8,16,16,8,16,16,8,16,16,8,8},
        
    //7. Doraemon
    {NG3,NC4,NC4,NE4,NA4,NE4,NG4,0,NG4,NA4,NG4,NE4,NF4,NE4,ND4,0,NA3,ND4,ND4,NF4,NB4,NB4,NA4,NG4,NF4,NF4,NE4,ND4,NA3,0,NA3,NB3,NC4,ND4,0,0,NG3,NC4,NC4,NE4,NA4,NE4,NG4,0,NG4,NA4,NG4,NE4,NF4,NE4,ND4,0,NA3,ND4,ND4,NF4,NB4,NB4,NA4,NG4,NF4,NF4,NE4,ND4,NA3,0,NA3,NB3,ND4,NC4,0,0,NA4,0,NA4,NG4,NF4,NG4,NA4,NG4,0,ND4,NE4,NFS4,ND4,NG4,0,NA4,0,NG4,0,NF4,0,ND4,0,NB4,NA4,NG4,NA4,NG4,NF4,0,0,NG4,NA4,NE4,0,ND4,NC4,0,0,NA4,0,NA4,NG4,NF4,NG4,NA4,NG4,0,ND4,NE4,NFS4,ND4,NG4,0,NA4,0,NG4,0,NF4,0,ND4,0,NB4,NA4,NG4,NA4,NG4,NF4,0,0,NG4,NA4,NE4,0,ND4,NC4},
    {2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,4,4,4,2,1,1,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,4,4,4,2,1,1,2,4,2,4,4,4,4,2,4,2,4,2,4,1,2,2,4,2,4,2,1,2,4,2,4,2,4,2,4,2,4,2,4,1,4,4,1,1,1,2,4,2,4,4,4,4,2,4,2,4,2,4,1,2,2,4,2,4,2,1,2,4,2,4,2,4,2,4,2,4,2,4,1,4,4,1},
          
    //8. Жуки: Батарейка
    {ND4,ND4,ND4,NE4,ND4,NC4,NB3,0,0,NB3,NB3,NB3,NA3,NF3,NG3,NF3,0,0,ND4,ND4,ND4,NE4,ND4,NC4,NB3,NB3,0,0,NB3,0,0,NC4,ND4,NC4,NB3},
    {4,4,4,4,4,4,4,8,8,4,4,4,4,4,4,4,8,8,4,4,4,4,4,4,4,4,8,8,4,8,8,4,4,4,4},
     
    //9. Happy Birthday
    {NC4,NC4,ND4,NC4,NF4,NE4,NC4,NC4,ND4,NC4,NG4,NF4,NC4,NC4,NC5,NA4,NF4,NE4,ND4,NAS4,NAS4,NA4,NF4,NG4,NF4},
    {6,12,4,4,4,2,6,12,4,4,4,2,6,12,4,4,4,4,2,6,12,4,4,4,2},
          
    //10. Mario main them tempo 
    {NE7, NE7, 0, NE7,0, NC7, NE7, 0,NG7, 0, 0,  0,NG6, 0, 0, 0, NC7, 0, 0, NG6,0, 0, NE6, 0,0, NA6, 0, NB6,0, NAS6, NA6, 0, NG6, NE7, NG7,NA7, 0, NF7, NG7,0, NE7, 0, NC7,ND7, NB6, 0, 0, NC7, 0, 0, NG6,0, 0, NE6, 0,0, NA6, 0, NB6,0, NAS6, NA6, 0, NG6, NE7, NG7,NA7, 0, NF7, NG7,0, NE7, 0, NC7,ND7, NB6, 0, 0},
    {12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,9, 9, 9,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,9, 9, 9,12, 12, 12, 12,12, 12, 12, 12,12, 12, 12, 12,},
          
    //11. Mario Underworld melody
    {NC4, NC5, NA3, NA4,NAS3, NAS4, 0,0,NC4, NC5, NA3, NA4,NAS3, NAS4, 0,0,NF3, NF4, ND3, ND4,NDS3, NDS4, 0,0,NF3, NF4, ND3, ND4,NDS3, NDS4, 0,0, NDS4, NCS4, ND4,NCS4, NDS4,NDS4, NGS3,NG3, NCS4,NC4, NFS4, NF4, NE3, NAS4, NA4,NGS4, NDS4, NB3,NAS3, NA3, NGS3,0, 0, 0},
    {12, 12, 12, 12,12, 12,3,12, 12, 12,12,12, 12, 6,3,12, 12, 12, 12,12, 12, 6,3,12, 12, 12, 12,12, 12, 6,6, 18, 18, 18,6, 6,6, 6,6,6,18, 18, 18, 18, 18, 18,10, 10, 10,10, 10, 10,3, 3, 3},
           
    //12. Bumer
    {NF6, NA6, 0, NA6, NF6, 0, NA6, NG6, NA6, NG6, NA6, NG6, NA6, NG6, NA6, NB6},
    {8, 2, 4, 8, 2, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2},
          
    //13.
    {NC4, NA3, NC4, NF3, NC4, NC4, NC4, NC4, NA3, NC4, NC4, NC4, NF3, NA3, NG3, NA3, NG3, NG3, NA3, NG3, NG3, NG3, NA3, NG3, NA3, NC4, NA3, NG3, NG3, NF3, NC4, NC4, NC4, NC4, NC4, NA3, NC4},
    {16,16,4,2,16,16,8,8,2,16,16,4,2,16,16,8,8,8,8,2,16,16,2,16,16,8,8,8,8,4,4,1,16,16,16,16,1},
        
    //14.
    {ND4, NG4, NG4, NA4, NG4, NF4, NE4, NC4, NE4, NA4, NA4, NB4, NA4, NG4, NF4, ND4, ND4, NB4, NB4, NC5, NB4, NA4, NG4, NE4, ND4, ND4, NE4, NA4, NF4, NG4},
    {4, 4, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 4, 4, 4, 2},
          
    //15.
    {NA4, NA4, NA4, NF4, NC5, NA4, NF4, NC5, NA4, NE5, NE5, NE5, NF5, NC5, NA4, NF4, NC5, NA4},
    {4, 4, 4, 5, 16, 4, 5, 16, 2, 4, 4, 4, 5, 16, 4, 5, 16, 2},
          
    //16. Star wars
    {NC3, NC3, NC3, NF3, NC4, NB3, NA3, NG3, NF4, NC4, NB3, NA3, NG3, NF4, NC4, NB3, NA3, NB3, NG3, NC3, NC3, NC3, NF3, NC4, NB3, NA3, NG3, NF4, NC4, NB3, NA3, NG3, NF4, NC4, NB3, NA3, NB3, NG3, NC3, NC3, ND3, NC4, NB3, NA3, NG3, NF3, NF3, NG3, NA3, NG3},
    {8,8,16,2,2,8,16,8,2,4,8,16,8,2,4,8,16,8,2,8,8,16,2,2,8,16,8,2,4,8,16,8,2,4,8,16,8,2,4,16,2,8,8,8,8,8,16,8,16,4},
           
    //17. Mission Imposible:
    {NE4,NF4,NE4,NF4,NE4,NF4,NE4,NF4,NE4,NF4,NE4,NF4,NE4,NF4,NE4,NF4,NG4,0,NG4,0,NF4,0,NF4,0,NG4,0,NG4,0,NA4,0,NC5,0,NA4,NG4,ND4,0,NA4,NG4,NC4,0,NA4,NG4,NC4,0,NA3,NC4},
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,16,8,16,8,16,16,16,16,16,8,16,8,16,16,16,16,16,16,2,32,16,16,2,32,16,16,2,16,16,16},
           
    //18. Jammes Bond
    {ND3,NF3,NF3,NF3,NF3,ND3,ND3,ND3,ND3,NF3,NF3,NF3,NF3,NF3,NF3,NF3,ND3,NF3,NF3,NF3,NF3,ND3,ND3,ND3,ND3,NF3,NF3,NF3,NF3,NF3,NE3,ND3,ND4,ND4,NA3,NG3,NA3},
    {16,32,32,16,8,16,16,16,16,32,32,16,8,16,16,16,16,32,32,16,8,16,16,16,16,32,32,16,8,16,16,16,16,2,16,16,2},
           
    //19. Chip n dale
    {0,NG4,NG4,NG4,NG4,NG4,NG4,0,NG4,ND4,NF4,NG4,NG4,NG4,NG4,NG4,NG4,NA4,NG4,NG4},
    {4,8,8,8,8,4,2,8,4,8,4,8,8,8,8,4,4,8,8,4},
           
    //20. Europe
    {NC4,NA3,NC4,NF3,NC4,NC4,NC4,NC4,NA3,NC4,NC4,NC4,NF3,NA3,NG3,NA3,NG3,NG3,NA3,NG3,NG3,NG3,NA3,NG3,NA3,NC4,NA3,NG3,NG3,NF3,NC4,NC4,NC4,NC4,NC4,NA3,NC4},
    {16,16,4,2,16,16,8,8,2,16,16,4,2,16,16,8,8,8,8,2,16,16,2,16,16,8,8,8,8,4,4,1,16,16,16,16,1},
           
     //21. Aqua
    {NG4,NE4,NG4,NC5,NA4,0,NF4,ND4,NF4,NB4,NG4,NF4,NE4,0,NE4,NC4,NF4,NC4,0,NF4,NE4,NG4,NF4},
    {8,8,8,8,4,4,8,8,8,8,4,8,8,4,8,8,4,4,4,8,8,4,4},
           
     //22. ABBA: MoneyMoney
    {NE4,NE4,NE4,NE4,NE4,NE4,NE3,NA3,NC4,NE4,ND4,ND4,ND4,ND4,ND4,ND4,NF3,NA3,NC4,ND4,ND4,NC4,NA3,NC4,NC4,NA3,NA3,NC4,NE4,NA4},
    {8,8,8,8,8,8,16,16,16,16,8,8,8,8,8,8,16,16,16,16,4,8,8,8,4,2,32,32,32,8},
      
    //23. Белые розы:
    {NB3,NB3,NB3,NB3,NF3,0,NB3,NB3,NB3,NB3,NF3,0,NB3,NG3,NF3,NG3,NF3,NG3,0,0,0,NA3,NA3,NA3,NA3,NE3,0,NA3,NA3,NA3,NA3,NE3,0,NA3,NF3,NE3,NF3,NE3,NF3},
    {8,8,8,4,4,8,8,8,8,4,4,8,4,4,8,8,8,4,8,8,8,8,8,8,4,4,8,8,8,8,4,4,8,4,4,8,8,8,4},
           
    //24. ДДТ - Оcень
    {NE4,NC4,NB3,NA3,NE4,NB3,NB3,NC4,NB3,NA3,NA3,NA3,NA3,NA3,NA3,NA3,NC4,NE4,NG4,NF4,ND4,ND4,ND4,ND4,NG4,NF4,NE4,ND4,NE4,NE4,NE4,ND4,NC4,NA3,0,NB3,NB3,NG4,NF4,NE3,NE3,NE4,NC4,NB3,NA3},
    {8,16,8,8,8,8,16,8,8,2,8,16,8,8,8,8,16,8,8,2,8,16,8,8,8,8,8,8,8,8,16,8,8,4,8,8,8,8,8,8,16,8,8,8,2},
          
    //25. Футбольный марш
    {NC4,NC4,NC4,NB3,NC4,ND4,NE4,0,ND4,NC4,NG3,NE4,NE4,NE4,ND4,NE4,NF4,ND4,0,NG4,NG4,NG4,NB4,0,NA4,NG4,NA4,NG4,0,NF4,NE4,NF4,NE4,NE4,ND4,NC4,ND4,NE4,NC4},
    {8,8,16,16,16,16,8,16,16,8,8,8,8,16,16,16,16,8,16,16,8,8,8,16,16,8,8,8,16,16,8,8,8,8,16,16,16,16,2},
         
    //26. Mozart 40
    {NA4,NG4,0,NG4,0,NA4,NG4,0,NG4,0,NA4,NG4,0,NG4,NE5,0,0,NE5,ND5,0,NC5,0,NC5,NB4,0,NA4,0,NA4,0,NG4,0,NF4,0,NF4,0,0,NG4,0,NF4,0,NF4,0,NG4,NF4,0,NF4,0,NG4,NF4,0,NF4,ND5,0,0,ND5,NC5,NC5,0,NC5,NA4,NG4,0,0,NG4,NF4,NE4,0,NE4,0,0,NE5,ND5,0,ND5,NF5,NC5,ND5,NC5,NG4,0,NE5,0,ND5,0,ND5,NF5,NC5,ND5,NC5,NE5,ND5,NC5,NB4,NA4,NG4,NG4,NG4,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3,0,NG3},
    {8,16,16,8,8,8,16,16,8,8,8,16,16,4,8,4,16,8,16,16,8,8,8,16,16,8,8,16,32,16,16,8,8,8,4,8,16,32,16,32,8,8,8,16,16,8,8,8,16,16,4,8,4,8,8,8,8,8,8,8,16,8,32,8,8,8,8,8,4,8,8,16,16,4,4,4,4,4,4,4,16,32,16,16,4,4,4,4,4,4,8,8,8,8,1,1,2,4,16,16,16,16,2,4,16,16,16,16,2,4,16,16,16,16,8,8,16,16,16,16,8,8,16,16,16,16,2},
        
    //27. Toreador
    {NC5,ND5,NC5,NA4,NA4,NA4,0,NG4,NA4,NA4,NA4,0,NA4,NG4,NC5,NA4,0,NF4,ND4,NG4,NC4,0,NG4,NG4,ND5,NC5,NA4,NA4,0,NG4,NA4,NA4,NA4,0,NE4,NA4,NA4,NG4,NB4,NE5,0,ND5,NE5,ND5,NC5,ND5,NG4,NA4,NA4,0,NA4,NA4,NA4,NF4,ND5,NC5,0,NF4,NG4,NF4,NC4,NA4,NA4,0,NG4,0,NF4,0},
    {4,8,16,4,4,8,16,16,8,16,4,4,4,8,16,4,4,4,8,16,4,4,2,8,8,8,8,16,32,8,8,8,4,4,4,4,4,8,8,1,8,32,16,32,8,8,8,8,4,8,32,16,32,8,8,4,4,32,16,32,8,8,8,8,8,8,8,2},
//          
    //28. Черепашки Ниндзя
    {0,NG4,NA4,NG4,NA4,NG4,NA4,NG4,0,NA4,NA4,NC5,NA4,NC5,ND5,NC5,NA4,0,NC5,NF5,NF5,ND5,NF5,NG5,NF5,ND5,0,NF5,NC5,NC5,NC5,NC5,NA4,NC5,NC5,NC5,NC5,NC5  },
    {4,8,8,8,8,8,16,8,16,8,8,8,8,8,8,16,8,16,8,8,8,8,8,8,16,8,16,8,16,16,16,16,8,4,16,16,16,8},
//          
    //29. Фристайлер
    {NF4,ND4,NA3,NF4,ND4,NA3,NF4,ND4,NA3,NE4,ND4,NA3,NE4,ND4,NA3,NC4,NA3,NF3,NC4,NA3,NF3,NC4,NA3,NF3,ND4,NC4,NG3,ND4,NC4,NG3,ND4,NG3},
    {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
//          
    //30. Mortal Kombat theme
    {NA3,NA3,NC4,NA3,ND4,NA3,NE4,ND4,NC4,NC4,NE4,NC4,NG4,NC4,NE4,NC4,NG3,NG3,NB3,NG3,NC4,NG3,ND4,NC4,NF3,NF3,NA3,NF3,NC4,NF3,NC4,NB3},
    {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
//          
    //31. БРИГАДА
    {NG3,ND4,NC4,NE4,ND4,ND4,NB3,NC4,ND4,NE4,ND4,NG3,NG3,ND4,NC4,NE4,ND4,NC4,NB3,NA3,NB3,NF3,NG3,ND4,NC4,NE4,ND4,ND4,NB3,NC4,ND4,NE4,ND4,NF3,0,0,NG3,NA3,NB3,NC4,NB3,NG3,0,NG3,NB3,NA3,NG3,NF3,NG3},
    {16,16,16,16,8,16,16,16,16,8,16,2,16,16,16,16,4,16,16,8,16,2,16,16,16,16,8,16,16,16,16,8,16,4,16,16,8,16,16,8,16,4,16,16,16,16,16,8,2},
//          
    //32. Crazy Frog - Axel F
    {NF3,0,NG3,0,NF3,0,NF3,NA3,0,NF3,0,ND3,0,NF3,0,NC4,0,NF3,0,NF3,NC4,0,NC4,0,NG3,0,NF3,0,NC4,0,NF4,0,NF3,ND3,0,ND3,NC3,0,NG3,0,NF3},
    {8,16,8,16,16,16,16,16,16,16,16,16,16,8,16,8,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,4},
//          
//    //33. Хава-Нагила
    {NE3,NE3,0,NG3,NF3,NE3,NG3,NG3,0,NB3,NA3,NG3,NA3,NA3,0,NC4,NB3,NA3,NG3,NF3,NE3,0,0},
    {4,4,8,8,8,8,4,4,8,8,8,8,4,4,8,8,8,8,4,4,4,8,8},
//          
//    //34. Свадебный марш Мендельсона
    {NC2,NC2,NC2,NC2,0,NC3,NC3,NC3,NC3,0,NC4,NC4,NC4,NC3,NB4,NF4,NA4,NG4,NF4,ND4,NC4,NB3,NC4,ND4,NG3,ND4,NE4,0,NC3,NB4,NF4,NA4,NG4,NF4,ND4,NC4,NB3,NC4,NE4,ND4,NE4,ND4,NC4,0},
    {16,16,16,8,2,16,16,16,8,2,16,16,16,2,2,8,4,4,4,4,4,8,8,4,8,8,2,4,2,2,8,4,4,4,4,4,8,8,4,8,8,2,2,4},
//          
);
 
int sizes[] = {68, 98, 84, 86, 64, 64, 148, 35, 25, 79, 55, 16, 37, 30, 18, 50, 46, 37, 20, 37, 23, 30, 39, 45, 39, 127, 68, 38, 32, 31, 49, 41, 23, 44};
 
void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(buttonStop, INPUT);
    pinMode(buttonPrev, INPUT);
    pinMode(buttonNext, INPUT);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Hello, world!");
    
    Serial.begin(9600);
 }

unsigned long aktualnyCzas = 0, poprzedniCzas = 0, roznicaCzasu;
int thisNote = 0, noteDuration = 0, pauseBetweenNotes = 0;

void loop() {
  
  playSong(31);
  
  delay(2000);
}

void playSong(int songNumber){
  thisNote = 0;
  size = sizes[songNumber];
  
  for (int i = 0; i < size; i++) {
    melody[i*2] = melodies[songNumber*2][i];
  }
  for (int i = 0; i < size; i++) {
    melody[i*2 + 1] = melodies[songNumber*2+1][i];
  }

  while(true){
    aktualnyCzas = millis();
    roznicaCzasu = aktualnyCzas - poprzedniCzas;
    
    noteDuration = 1000/melody[thisNote * 2 +1];
    pauseBetweenNotes = noteDuration * 1.80;

    if(roznicaCzasu >= pauseBetweenNotes){
      poprzedniCzas = aktualnyCzas;
      buzz(buzzer, melody[thisNote*2],noteDuration);
      noTone(buzzer);
      
      thisNote++;
    }

    if(digitalRead(buttonStop)) break;
    if(thisNote == size) break;
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(delayValue);
  }
  digitalWrite(13, LOW);
 
}
