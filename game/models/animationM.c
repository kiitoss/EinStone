#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
MLV_Animation *get_animation(MLV_Image *sprite, int rectsize, int row_animation, int first_frame, int last_frame, int time) {
  int i;
  MLV_Image *images[MAX_FRAMES];
  MLV_Animation *animation;
  MLV_Sound *sound;
  int nb_frames;
  
  nb_frames = last_frame - first_frame;
  if (nb_frames > MAX_FRAMES) {
    first_frame = MAX_FRAMES - last_frame;
  }
  
  if (!sprite) {
    printf("--> L'image n'a pas pu être chargée.\n");
    exit(1);
  }
  
  animation = MLV_create_animation(nb_frames, 1, 1);
  for (i=0; i<nb_frames; i++) {
    images[i] = MLV_copy_partial_image(sprite, 64*(i+first_frame), 64*row_animation, 64, 64);
    MLV_resize_image(images[i], rectsize, rectsize);
    MLV_add_frame_in_animation(images+i, &sound, time, animation);
  }
  return animation;
}
