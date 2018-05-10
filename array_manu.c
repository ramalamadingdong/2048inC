void waitFor (unsigned int secs) {
  unsigned int retTime = time(0) + secs;   // Get finishing time.
  while (time(0) < retTime);               // Loop until it arrives.
}

int spawn (int a[4][4]){

  int cnt = 0;
  int x = rand_lim(3);
  int y = rand_lim(3);
  ran = rand_lim(100);

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if (a[i][j]){
 	cnt++;
      }
      if (cnt == 16){
	ALLEGRO_FONT *fonts = al_load_ttf_font("pirulen.ttf",36,0);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display));
	al_draw_text(fonts, al_map_rgb(255,255,255) ,SCREEN_W/2 ,SCREEN_W/2 , ALLEGRO_ALIGN_CENTRE, "YOU LOSE");
	al_flip_display();
	waitFor(5);
	return -1;
      }
    }
  }

  if (!a[x][y] && ran <= 80)
    a[x][y] = 2;
  else if (!a[x][y] && ran >= 20){a[x][y]=4;}
  else{
    spawn(a);
    return 0;
  }
  return 0;
}

void new_box_u (int p, int f, int a[4][4], int i, int j){
  
  int g = p+f;
  if (a[i][j] < g){
    a[i][j] = g;
    a[i][j+1] =0;
  }
}

void new_box_d (int p, int f, int a[4][4], int i, int j){
  
  int g = p+f;
  if (a[i][j] < g){
    a[i][j] = g;
    a[i][j-1] =0;
  }
}
void new_box_r (int p, int f, int a[4][4], int i, int j){
  
  int g = p+f;
  if (a[i][j] < g){
    a[i][j] = g;
    a[i-1][j] =0;
  }
}

void new_box_l (int p, int f, int a[4][4], int i, int j){
  
  int g = p+f;
  if (a[i][j] < g){
    a[i][j] = g;
    a[i+1][j] =0;
  }
}



void shift_l (int a[4][4]){
  
  int i,j;
  
  for(i = 1; i < 4; i++){
    for(j = 0; j < 4; j++){
      if (a[i][j] != a[i-1][j]){
	
	if (!(a[i-1][j])){
	  a[i-1][j] = a[i][j];
	  a[i][j] = 0;
	  shift_l(a);
	}
      }
      
      if (a[i][j]==a[i-1][j] && a[i][j] && a[i-1][j])
	{
	  if (!(a[i-1][j]) || a[i][j] != a[i-1][j]){
	    a[i-1][j] = a[i][j];
	    a[i][j] = 0;
	    shift_l(a);
	  }
	  new_box_l(a[i][j], a[i-1][j], a, (i-1), (j));
	  shift_l(a);
	}
    }
  }
}

void shift_r (int a[4][4]){
  
  int i,j;
  
  for(i = 0; i < 3; i++){
    for(j = 0; j < 4; j++){
      if (a[i][j] != a[i+1][j]){
	
	if (!(a[i+1][j])){
	  a[i+1][j] = a[i][j];
	  a[i][j] = 0;
	  shift_r(a);
	}
      }
      
      if (a[i][j]==a[i+1][j] && a[i][j] && a[i+1][j])
	{
	  if (!(a[i+1][j]) || a[i][j] != a[i+1][j]){
	    a[i+1][j] = a[i][j];
	    a[i][j] = 0;
	    shift_r(a);
	  }
	  new_box_r(a[i][j], a[i+1][j], a, (i+1), (j));
	  shift_r(a);
	}
    }
  }
}

void shift_u (int a[4][4]){
  
  int i,j;
  
  for(i = 0; i < 4; i++){
    for(j = 1; j < 4; j++){
      if (a[i][j] != a[i][j-1]){
	
	if (!(a[i][j-1])){
	  a[i][j-1] = a[i][j];
	  a[i][j] = 0;
	  shift_u(a);
	}
      }
      
      if (a[i][j]==a[i][j-1] && a[i][j] && a[i][j-1])
	{
	  if (!(a[i][j-1]) || a[i][j] != a[i][j-1]){
	    a[i][j-1] = a[i][j];
	    a[i][j] = 0;
	    shift_u(a);
	  }
	  new_box_u(a[i][j], a[i][j-1], a, i, (j-1));
	  shift_u(a);
	}
    }
  }
}


void shift_d (int a[4][4]){
  
  int i,j;
  
  for(i = 0; i < 4; i++){
    for(j = 0; j < 3; j++){
      if (a[i][j] != a[i][j+1]){
	
	if (!(a[i][j+1])){
	  a[i][j+1] = a[i][j];
	  a[i][j] = 0;
	  shift_d(a);
	}
      }
      
      if (a[i][j]==a[i][j+1] && a[i][j] && a[i][j+1]){
	
	if (!(a[i][j+1]) || a[i][j] != a[i][j+1]){
	  a[i][j+1] = a[i][j];
	  a[i][j] = 0;
	  shift_d(a);
	}
	new_box_d(a[i][j], a[i][j+1], a, i, (j+1));
	shift_d(a);
      }
    }
  }
}
