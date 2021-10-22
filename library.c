#include "library.h"
#include "song.h"
#include <ctype.h>

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

}
void print_songs(struct song_node **lib, char letter){

}
void print_artist_songs(struct song_node **lib, char *artist){

}
void print_library(struct song_node **lib){

}
struct song_node *shuffled_list(struct song_node **lib){

}
void delete_song(struct song_node **lib, song_node *del){

}
void free_lib(struct song_node **lib){

}
