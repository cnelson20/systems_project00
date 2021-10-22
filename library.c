#include "library.h"
#include "song.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct song_node **create_library() {
  song_node **lib= calloc(27,sizeof(struct song_node *));
  return lib;
}
void add_song(struct song_node **lib, struct song_node *song){
  int artist;
  artist = tolower(song->artist[0]) - 'a';
  if(artist >= 0 && artist < 26) {
    lib[artist] = insert_node(lib[artist],song);
  } else {
    lib[26] = insert_node(lib[26],song);
  }
}
struct song_node *find_song(struct song_node **lib, char *name, char *artist){
  int creator;
  creator = tolower(artist[0]) - 'a';
  if(creator >= 0 && artist < 26) {
    return find_song(lib[creator],name,artist);
  } else {
    return find_song(lib[creator],name,artist);
  }
}
struct song_node *find_artist(struct song_node **lib, char *artist){
  int letter;
  letter  = (del->artist[0]) - 'a';
  if(letter >= 0 && letter < 26) {
     return find_first_song(lib[letter],artist);
  } else {
    return find_first_song(lib[26],artist);
  }
  return NULL;
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
  int letter;
  letter  = (del->artist[0]) - 'a';
  if(letter >= 0 && letter < 26) {
     return remove_song(lib[letter],del->name,del->artist);
  } else {
    return remove_song(lib[26],del->name,del->artist);
  }
}
struct song_node **free_lib(struct song_node **lib){
  int i;
  for (i = 0; i < 27; i++) {
    free_list(lib[i]);
  }
  free(lib);
  return NULL;
}
