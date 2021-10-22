#include "library.h"
#include "song.h"
#include <ctype.h>

struct song_node **create_library() {
  song_node **lib= malloc(27* sizeof(struct song_node *));
}
void add_song(struct song_node **lib, struct song_node *song){
  
}
struct song_node *find_song(struct song_node **lib, char *name, char *artist){

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
