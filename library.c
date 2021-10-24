#include "library.h"
#include "song.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a < b ? a : b)

int listlength(struct song_node *s);
struct song_node *shuffled_list_helper(struct song_node **lib, int length, struct song_node *shuf);
int in_list(struct song_node *needle, struct song_node *haystack);

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

struct song_node *shuffled_list_helper(struct song_node **lib, int length, struct song_node *shuf){
  int lengths[27];
  int counter, random;
  int sizecount = 0;
  struct song_node *rand_node, *chosen_node;
  for (counter = 0; counter < 27; counter++) {
    sizecount += listlength(lib[counter]);
    lengths[counter] = sizecount;
  }
  do {
	random = rand() % sizecount;
	//printf("Rand: %d\n",random);
	  
	counter = 0;
	while (counter == 26 || random >= lengths[counter]) {
	  counter++;
	}
	random -= (counter == 0 ? 0 : lengths[counter-1]);
	chosen_node = lib[counter];
	while (random--) {chosen_node = chosen_node->next;}
  
  } while (in_list(chosen_node,shuf));
  
  rand_node = malloc(sizeof(struct song_node));
  strncpy(rand_node->name,chosen_node->name,SONG_ARTISTLENGTH - 1);
  strncpy(rand_node->artist,chosen_node->artist,SONG_ARTISTLENGTH - 1);
  if(length <= 1) {
    rand_node->next = NULL;
  } else {
    rand_node->next = shuffled_list_helper(lib,MIN(length - 1,sizecount-1),rand_node);
  }
  return rand_node;
}
struct song_node *shuffled_list(struct song_node **lib, int length) {
 return shuffled_list_helper(lib,length,NULL);
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

int listlength(struct song_node *s) {
  int l = 0;
  while (s) {
    s = s->next;
    l++;
  }
  return l;
}
int in_list(struct song_node *needle, struct song_node *haystack) {
	while (haystack) {
	  if (compare_songs(needle,haystack) == 0) {
		return 1;
	  }		  
	  haystack = haystack->next;
	}
	return 0;
}
