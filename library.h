#include "song.h"

#ifndef __library_myTunes__
#define __library_myTunes__
struct song_node **create_library();
void add_song(struct song_node **lib, struct song_node *song);
struct song_node *find_song_library(struct song_node **lib, char *name, char *artist);
struct song_node *find_artist_library(struct song_node **lib, char *artist);
void print_letter(struct song_node **lib, int letter);
void print_artist_songs(struct song_node **lib, char *artist);
void print_library(struct song_node **lib);
struct song_node *shuffled_list(struct song_node **lib, int length);
void delete_song(struct song_node **lib, struct song_node *del);
struct song_node **clear_lib(struct song_node **lib);
#endif
