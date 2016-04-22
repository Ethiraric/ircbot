/*
** youtube_title.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon May 11 23:10:43 2015 Florian SABOURIN
** Last update Mon May 11 23:10:43 2015 Florian SABOURIN
*/

#include "dev_key.h"

#ifndef YOUTUBE_KEY
# error "Please define your youtube key as YOUTUBE_KEY in dev_key.h"
#endif

#include <stdlib.h>
#include <curl/curl.h>
#include "luneth.h"

// Callback function

static size_t	write_callback(char *ptr, size_t size, size_t nmemb, void *dat)
{
  t_buffer	*buff;

  buff = dat;
  if (buffer_append(buff, ptr, size * nmemb))
    return (0);
  return (size * nmemb);
}

static char	*extract_code(t_buffer *json)
{
  char		*pos;
  char		*ret;

  ret = NULL;
  pos = memmem(buffer_data(json), buffer_size(json),
	       "\"title\": \"", 10);
  if (pos)
    {
      pos += 10;
      ret = strndup(pos, rawmemchr(pos, '"') - (void *)pos);
    }
  buffer_delete(json);
  return (ret);
}

char		*youtube_title(const char *code)
{
  CURLcode	res;
  t_buffer	buff;
  CURL		*handler;
  char		*url;
  int		ret;

  ret = asprintf(&url, "https://www.googleapis.com/youtube/v3/videos?key="
		 YOUTUBE_KEY "&part=snippet&id=%s", code);
  if (ret == -1)
    return (NULL);
  handler = curl_easy_init();
  if (!handler)
    {
      free(url);
      return (NULL);
    }
  buffer_new(&buff);
  curl_easy_setopt(handler, CURLOPT_URL, url);
  curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, &write_callback);
  curl_easy_setopt(handler, CURLOPT_WRITEDATA, &buff);
  res = curl_easy_perform(handler);
  curl_easy_cleanup(handler);
  free(url);
  if (res != CURLE_OK)
    {
      fprintf(stderr, "err:%s\n", curl_easy_strerror(res));
      buffer_delete(&buff);
      return (NULL);
    }
  return (extract_code(&buff));
}
