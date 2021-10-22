#include "library.h"
#include "song.h"
#include <ctype.h>

struct song_node **create_library() {
  song_node **lib= calloc(27,sizeof(struct song_node *));
  return lib;
}
void add_song(struct song_node **lib, struct song_node *song){
  
}
struct song_node *find_song(struct song_node **lib, char *name, char *artist){

}
struct song_node *find_artist(struct song_node **lib, char *artist){

}
void print_songs(struct song_node **lib, char letter){
  int letter = tolower(letter) - 'a';
  if (letter < 0 || letter >= 26) {letter = 26;}
  print_list(lib[letter]);
}
void print_artist_songs(struct song_node **lib, char *artist){
  int letter = tolower(letter) - 'a';
  if (letter < 0 || letter >= 26) {letter = 26;}
  struct song_node *firstsong = find_first_song(lib[letter],artist);
  while (firstsong && strcmp(artist,firstsong->artist) == 0) {
    print_song(firstsong);
    firstsong = firstsong->next;
  }
}
void print_library(struct song_node **lib){

}
struct song_node *shuffled_list(struct song_node **lib){

}
void delete_song(struct song_node **lib, song_node *del){

}
struct song_node **free_lib(struct song_node **lib){
  int i;
  for (i = 0; i < 27; i++) {
    free_list(lib[i]);
  }
  free(lib);
  return NULL;
}
