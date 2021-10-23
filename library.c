#include "library.h"
#include "song.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct song_node **create_library() {
  struct song_node **lib= malloc(27 * sizeof(*lib));
  int i;
  for (i = 0; i < 27; i++) {
	lib[i] = NULL;
  }
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
struct song_node *find_song_library(struct song_node **lib, char *name, char *artist){
  int creator;
  creator = tolower(artist[0]) - 'a';
  if(creator >= 0 && creator < 26) {
    return find_song(lib[creator],name,artist);
  } else {
    return find_song(lib[creator],name,artist);
  }
}
struct song_node *find_artist_library(struct song_node **lib, char *artist){
  int letter = (artist[0]) - 'a';
  if(letter >= 0 && letter < 26) {
     return find_first_song(lib[letter],artist);
  } else {
    return find_first_song(lib[26],artist);
  }
  return NULL;
}
void print_letter(struct song_node **lib, int letter){
  letter = tolower(letter) - 'a';
  if (letter < 0 || letter >= 26) {letter = 26;}
  print_list(lib[letter]);
}
void print_artist_songs(struct song_node **lib, char *artist){
  struct song_node *firstsong = find_artist_library(lib,artist);
  struct song_node *copy = firstsong;
  if (firstsong == NULL) {
	printf("artist not found!\n");
	return;
  }
  printf("[ ");
  while (firstsong && strcasecmp(copy->artist,firstsong->artist) == 0) {
    if (copy != firstsong) {printf(" | ");}
    printf("%s: %s",firstsong->artist,firstsong->name);
    firstsong = firstsong->next;
  }
  printf(" ]\n");
}
void print_library(struct song_node **lib){
  int i;
  for (i = 0; i < 27; i++) {
    if (lib[i] != NULL) {
		printf("%c: ",i+'A');
		print_list(lib[i]);
	}
  }
  printf("\n");
}
struct song_node *shuffled_list(struct song_node **lib, int length){

}
void delete_song(struct song_node **lib, struct song_node *del){
  if (del == NULL) {printf("Cannot delete null value!\n");return;}
  int letter;
  letter  = tolower(del->artist[0]) - 'a';
  if(letter >= 0 && letter < 26) {
    lib[letter] = remove_song(lib[letter],del->name,del->artist);
  } else {
    lib[letter] = remove_song(lib[26],del->name,del->artist);
  }
}
struct song_node **clear_lib(struct song_node **lib){
  int i;
  for (i = 0; i < 27; i++) {
    if (lib[i] != NULL) {free_list(lib[i]);}
	lib[i] = NULL;
  }
  return lib;
}
