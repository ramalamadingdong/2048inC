#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include <allegro5/allegro_ttf.h>
#include "defines.h"
#include "GUI.c"
#include "array_manu.c"

void usage(char const * name){
  printf("Usage %s [-c <for just colors> or -n <for numbers and colors>]\n", name);
}
    
int parseArgs(int argc, char const * const argv[]){
  int i;

  for (i=1; i < argc; i++){
    
    if(strcmp("-h", argv[i]) ==0){
      usage(argv[0]);
      return -1;
    }
    else if (strcmp("-n", argv[i]) ==0){
      l_c = 1;
      return 0;
    }
    else if (strcmp("-c", argv[i]) == 0){
      l_c = 0;
      return 0;
    }
    else{
      usage(argv[0]);
      return -1;
    }
  }

}

   
int main(int argc, char const * const argv[]){
  
int err =  parseArgs(argc, argv);
 if (err) 
   return -1;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   
  bool key[4] = { false, false, false, false };
   
  bool redraw = true;
  bool doexit = false;
  
  init();
  initrand();
  
  event_queue = al_create_event_queue();
  if(!event_queue) {
    fprintf(stderr, "failed to create event_queue!\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    return -1;
  }
  
  al_register_event_source(event_queue, al_get_display_event_source(display));
  
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  
  al_register_event_source(event_queue, al_get_keyboard_event_source());
   
  al_clear_to_color(al_map_rgb(220,220,220));
  
  
  al_flip_display();
   
  al_start_timer(timer);
   
  while(!doexit)
    {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
       
      if(ev.type == ALLEGRO_EVENT_TIMER) {
	if(key[KEY_UP]) {
	}
	 
	if(key[KEY_DOWN]) {
	}
	 
	if(key[KEY_LEFT]) {
	}
	 
	if(key[KEY_RIGHT]) {
	}
	redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	break;
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	switch(ev.keyboard.keycode) {
	case ALLEGRO_KEY_UP:
	  key[KEY_UP] = true;
	  break;
	   
	case ALLEGRO_KEY_DOWN:
	  key[KEY_DOWN] = true;
	  break;
	
	case ALLEGRO_KEY_LEFT: 
	  key[KEY_LEFT] = true;
	  break;
	       
	case ALLEGRO_KEY_RIGHT:
	  key[KEY_RIGHT] = true;
	  break;
	}
      }

      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
	switch(ev.keyboard.keycode) {
	case ALLEGRO_KEY_UP:
	  key[KEY_UP] = false;
	  shift_u(a);
	  errs = spawn(a);
	  draw_boxes(a);
	  break;
	   
	case ALLEGRO_KEY_DOWN:
	  key[KEY_DOWN] = false;
	  shift_d(a);
	  errs = spawn(a);
	  draw_boxes(a);
	  break;
	   
	case ALLEGRO_KEY_LEFT: 
	  key[KEY_LEFT] = false;
	  shift_l(a);
	  errs= spawn(a);
	  draw_boxes(a);
	  break;
	   
	case ALLEGRO_KEY_RIGHT:
	  key[KEY_RIGHT] = false;
	  shift_r(a);
	  errs = spawn(a);
	  draw_boxes(a);
	  break;
	   
	case ALLEGRO_KEY_ESCAPE:
	  doexit = true;
	  break;
	}
      }
       
      if(redraw && al_is_event_queue_empty(event_queue)) {
	redraw = false;
	drawgrid();
	 
      }
    }
	
   
  //--------------END OF CODE----------------------//
  //al_destroy_bitmap(bouncer);
  al_destroy_timer(timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue); 
  return 0;
}
