#ifndef ASSETS
#define ASSETS

#define WALL_ASSETS 2
#define WALL_ASSETS_Y 188

#define FROG_ASSETS_X 8
#define FROG_ASSETS_Y 3

#define FROG_CHARS_ASSETS 5
#define FROG_CHARS_ASSETS_Y 232
#define DEATH_ASSETS 7
#define DEATH_Y 80

#define CAR_ASSETS 5
#define CAR_Y 116

#define SNAKE_ASSETS 3
#define SNAKE_Y 170

#define CROCODRILE_ASSETS 2
#define CROCODRILE_Y 134
#define CROCODRILE_X 55

#define TURTLE_ASSETS 5
#define TURTLE_Y 152

#define LOG_ASSETS 3
#define LOG_Y 134

#define OTTER_X 91
#define OTTER_Y 152
#define OTTER_ASSETS 2

#define CHARS_ASSETS_X 17
#define CHARS_ASSETS_Y 3
#define CHARS_ASSETS 36
// Constantes para acceder a los assets de la frog
#define SPECIAL_ASSETS 6
#define SPECIAL_ASSETS_X 45
#define SPECIAL_ASSETS_Y 196

enum special_sprites {
    happy_frog,
    happy_frog_open, 
    fly,
    croco_close,
    croco_open,
    street
};
enum frog_sprites {
    // Rana Normal
    frog_top, 
    frog_jumping_top,
    frog_to_left,
    frog_jumping_left,
    frog_to_bottom,
    frog_jumping_bottom,
    frog_to_right,
    frog_jumping_right,
    // Rana violeta
    violet_frog_top, 
    violet_frog_jumping_top,
    violet_frog_to_left,
    violet_frog_jumping_left,
    violet_frog_to_bottom,
    violet_frog_jumping_bottom,
    violet_frog_to_right,
    violet_frog_jumping_right,
    // Rana roja
    red_frog_top, 
    red_frog_jumping_top,
    red_frog_to_left,
    red_frog_jumping_left,
    red_frog_to_bottom,
    red_frog_jumping_bottom,
    red_frog_to_right,
    red_frog_jumping_right,

};
// Constantes para acceder a las animaciones de muerte
enum death_sprites{
    death1,
    death2,
    death3,
    death4,
    death5,
    death6,
    death7,
    death8
};
// Constantes para acceder a los autos. l y r hacen referencia al sentido
enum cars_sprites {
    car1l,
    car2l,
    car3r,
    car4r,
    trackl
};
// Constanes para acceder al cocodrilo
enum crocodrile_sprites {
    crocodrile,
    crocodrile_open
};
// Constantes para acceder a las animaciones de tortuga
enum turtle_sprites {
    turtle1,
    turtle2,
    turtle3,
    turtle_fade1,
    turtle_fade2
};
// Constantes para acceder a las partes del tronco
enum log_sprites {
    start_log,
    log,
    end_log
};
// Constantes para acceder a la nutria
enum otther_sprites {
    otter_down,
    otter_up
};
typedef struct {
    float sx; 
    float sy;
    float sw;
    float sh;

} assets_t;
// Constantes para acceder a los caracteres
enum char_sprites{
    char_0,
    char_1,
    char_2,
    char_3,
    char_4,
    char_5,
    char_6,
    char_7,
    char_8,
    char_9,
    char_a,
    char_b,
    char_c,
    char_d,
    char_e,
    char_f,
    char_g,
    char_h,
    char_i,
    char_j,
    char_k,
    char_l,
    char_m,
    char_n,
    char_o,
    char_p,
    char_q,
    char_r,
    char_s,
    char_t,
    char_u,
    char_v,
    char_w,
    char_x,
    char_y,
    char_z,
};
enum wall_sprites {
    big_wall,
    small_wall
};
enum frog_char_sprites {
    frog_f,
    frog_r,
    frog_o,
    frog_g,
    frog_e
};
enum snake_sprites {
    snake1,
    snake2
};
assets_t * get_cars_assets(void);
assets_t * get_frog_assets(void);
assets_t * get_death_assets(void);
assets_t * get_snakes_assets(void);
assets_t * get_crocodrile_assets(void);
assets_t * get_turtle_assets(void);
assets_t * get_log_assets(void);
assets_t * get_otter_assets(void);
assets_t * get_chars_assets(char color);
assets_t * get_frog_chars_assets(void);
assets_t * get_special_assets(void);
assets_t * get_wall_assets(void);

#endif