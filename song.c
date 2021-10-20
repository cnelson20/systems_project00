#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node;
struct song_node *construct_song(char *n, char *art);
int compare_songs(struct song_node *a, struct song_node *b);
struct song_node *insert_front(struct song_node *head, struct song_node *new);
struct song_node * insert_node(struct song_node *head, struct song_node *new);
int  strcasecmp(const char *, const char *);
int print_song(struct song_node *s);
int print_list(struct song_node *head);
struct song_node *find_song(struct song_node *list,char *name, char *artist);
struct song_node *find_first_song(struct song_node *list,char *artist);
struct song_node *random_song(struct song_node *list);
int tolower(unsigned char ch);
int main();


struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

int main() {
  srand(time(NULL));
  
  struct song_node *a_to_z[27];
  a_to_z[0] = construct_song("Highway to Hell","AC-DC");
  a_to_z[0] = insert_node(a_to_z[0],construct_song("Thunderstruck","AC-DC"));
  a_to_z[0] = insert_node(a_to_z[0],construct_song("Dirty Deeds Done Dirt Cheap","AC-DC"));
  print_list(a_to_z[0]);

  printf("Should be Highway to Hell: ");print_song(find_song(a_to_z[0],"Highway to Hell","AC-DC"));
  printf("Should be D4C: ");print_song(find_first_song(a_to_z[0],"AC-DC"));
  printf("Random Song: ");print_song(random_song(a_to_z[0]));
}

struct song_node *insert_front(struct song_node *head,struct song_node *new) {
  new->next = head;
  return new;
}
struct song_node *insert_node(struct song_node *head, struct song_node *new) {
  struct song_node *copy = head;
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
  strncpy(s->name,n,100- 1);
  strncpy(s->artist,art,sizeof(s->artist) - 1);
  s->next = NULL;

  return s;
}
int print_song(struct song_node *s) {
  printf("%s by %s\n",s->name,s->artist);
  return 0;
}
int print_list(struct song_node *head) {
  while (head) {
    print_song(head);
    head = head->next;
  }
  printf("\n");
  return 0;
}

struct song_node *find_song(struct song_node *list,char *name, char *artist) {
  while (list) {
    if (strcasecmp(list->artist,artist) || strcasecmp(list->name,name)) {
      list = list->next;
    } else {
      return list;
    }
  }
  return NULL;
}
struct song_node *find_first_song(struct song_node *list,char *artist) {
  while (list) {
    if (strcasecmp(list->artist,artist)) {
      list = list->next;
    } else {
      return list;
    }
  }
  return NULL;
}
struct song_node *random_song(struct song_node *list) {
  struct song_node *copy = list;
  int length = 1;
  while (copy = copy->next) {length++;}
  int r = rand() % length;
  while (r) {
    list = list->next;
    r--;
  }
  return list;
}


int tolower(unsigned char ch) {
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
