int init (){
  
  if(!al_init()) {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }
  
  if (!al_init_image_addon()){
    fprintf(stderr, "failed to initialize the Image Addon!\n");
    return -1;
  }
  
  al_init_primitives_addon();
   
  if(!al_install_keyboard()) {
    fprintf(stderr, "failed to initialize the keyboard!\n");
    return -1;
  }
   
  timer = al_create_timer(1.0 / FPS);
  if(!timer) {
    fprintf(stderr, "failed to create timer!\n");
    return -1;
  }
     
  display = al_create_display(SCREEN_W, SCREEN_H);
   
  if(!display) {
    fprintf(stderr, "failed to create display!\n");
    al_destroy_timer(timer);
    return -1;
  }
  al_init_font_addon(); // initialize the font addon
  al_init_ttf_addon();// initialize the ttf (True Type Font) addon
  return 0;
}
int initrand(void) {
  struct timeval tv;
  int err = gettimeofday(&tv, 0);
  if (err) return -1;
  srand((unsigned int) tv.tv_usec);
  return 0;
}

int rand_lim(int limit) {
  
  int divisor = RAND_MAX/(limit+1);
  int retval;

  do { 
    retval = rand() / divisor;
  } while (retval > limit);

  return retval;
}

void drawgrid(){
  
  ALLEGRO_COLOR dark = al_map_rgb_f(0, 0, 0);
  
  al_draw_line(108, 0, 108, 432, dark, 3);
  al_draw_line(216, 0, 216, 432, dark, 3);
  al_draw_line(324, 0, 324, 432, dark, 3);
  
  al_draw_line(0, 108, 432, 108, dark, 3);
  al_draw_line(0, 216, 432, 216, dark, 3);
  al_draw_line(0, 324, 432, 324, dark, 3);
  al_flip_display();
}

void draw_boxes (int a[4][4]){
  
  al_clear_to_color(al_map_rgb(220,220,220));
   
  ALLEGRO_BITMAP *bouncer = NULL;
  ALLEGRO_BITMAP *bouncer2 = NULL;

  ALLEGRO_FONT *fonts = al_load_ttf_font("pirulen.ttf",36,0);
  
  int i, j;
  
  bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
  
  if(!bouncer) {
    
    fprintf(stderr, "failed to create bouncer bitmap!\n");   
    al_destroy_display(display);
    al_destroy_timer(timer);
  }
  

  bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
  
  if(!bouncer2) {
    
    fprintf(stderr, "failed to create bouncer bitmap!\n");   
    al_destroy_display(display);
    al_destroy_timer(timer);
  }
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if (a[i][j]){
	if (a[i][j] == 2){
	  
	  al_set_target_bitmap(bouncer);
	  al_clear_to_color(al_map_rgb(255, 0, 255));
	  al_set_target_bitmap(al_get_backbuffer(display));

	  al_draw_bitmap(bouncer, i*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,(i*108 +4), j*108 +4 , 0, "2");
	    
	}
	else if (a[i][j] ==4){
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(255, 255, 255));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, i*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(0, 0, 0) ,i*108 +4  , j*108 +4, 0, "4");
	}
	else if (a[i][j] == 8){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(0, 0, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "8");
	}
	else if (a[i][j] == 16){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(255, 0, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "16");
	}
	else if (a[i][j] == 32){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(0, 255, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "32");
	}
	else if (a[i][j] == 64){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(0, 0, 255));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "64");
	}
	else if (a[i][j] == 128){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(200, 150, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "128");
	}
	else if (a[i][j] == 256){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(255, 200, 90));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "256");
	}
	else if (a[i][j] == 512){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(50, 50, 50));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "512");
	}
	else if (a[i][j] == 1024){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(100, 200, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "1024");
	}
	else if (a[i][j] == 2048){
	  
	  al_set_target_bitmap(bouncer2);
	  al_clear_to_color(al_map_rgb(0, 100, 200));
	  al_set_target_bitmap(al_get_backbuffer(display));
	    
	  al_draw_bitmap(bouncer2, (i)*108 +4, j*108 +4, 0);
	  if (l_c)
	    al_draw_text(fonts, al_map_rgb(255,255,255) ,i*108 +4  , j*108 +4, 0, "2048");
	}
	else if (a[i][j] > 2048){
	  
	  al_clear_to_color(al_map_rgb(0, 0, 0));
	  al_set_target_bitmap(al_get_backbuffer(display));
	al_draw_text(fonts, al_map_rgb(255,255,255) ,SCREEN_W/2 ,SCREEN_W/2 , ALLEGRO_ALIGN_CENTRE, "YOU LOSE");
	}
      }                                          
    }
  }
  al_flip_display();
}
