#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node;
struct song_node *construct_song(char *n, char *art);
int compare_songs(struct song_node *a, struct song_node *b);
struct song_node *insert_front(struct song_node *head, char *n, char *art);
struct song_node * insert_node(struct song_node *head, struct song_node *new);
int  strcasecmp(const char *, const char *);
int print_list(struct song_node *head);
int main();


struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

int main() {
  struct song_node *a_to_z[26];
  a_to_z[0] = construct_song("Thunderstruck","AC-DC");
}

struct song_node *insert_front(struct song_node *head,char struct_node *new) {
  s->next = head;
  return new;
}
struct song_node *insert_node(struct song_node *head, struct song_node *new) {
  struct song_node *copy = *head;
  while (copy->next) {
    if (compare_songs(copy,new) > 0) {
      if (copy == head) {
	insert_front(head,new);
	return new;
      }
      return head;
    }
    copy = copy->next;
  }
  if (compare_songs(copy,new) > 0) {
    insert_front(copy,new);
    return new;
  } else {
    copy->next = new;
    return head;
  }
}

struct song_node *construct_song(char *n, char *art) {
  struct song_node *s = malloc(sizeof(struct song_node));
  strncpy(s->name,n,sizeof(s->name - 1));
  strncpy(s->artist,art,sizeof(s->artist - 1));
  s->next = NULL;

  return s;
}
  
int print_list(struct song_node *head) {
  while (head) {
    printf("%s by %s\n",head->name,head->artist);
  }
      printf("\n");
}

char tolower(unsigned char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch = 'a' + (ch - 'A');
    return ch;
 }

int strcasecmp(const char *s1, const char *s2) {
    const unsigned char *us1 = (const u_char *)s1,
                        *us2 = (const u_char *)s2;

    while (tolower(*us1) == tolower(*us2++))
        if (*us1++ == '\0')
            return (0);
    return (tolower(*us1) - tolower(*--us2));
}

int compare_songs(struct song_node *a, struct song_node *b) {
  int i;
  i = strcasecmp(a->artist,b->artist);
  if (i != 0) {return i;}
  return strcasecmp(a->name,b->name);
}
