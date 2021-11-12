#!/usr/bin/node
// prints all characters of a Star Wars movie
const argv = process.argv;
const urlFilm = 'https://swapi-api.hbtn.io/api/films/';
const urlMovie = `${urlFilm}${argv[2]}/`;
const request = require('request');

request(urlMovie, function (error, response, body) {
  if (error == null) {
    const body = JSON.parse(body);
    const char = body.characters;

    if (char && char.length > 0) {
      const limit = char.length;
      charRequest(0, char[0], char, limit);
    }
  } else {
    console.log(error);
  }
});

function charRequest (idx, url, characters, limit) {
  if (idx === limit) {
    return;
  }
  request(url, function (error, response, body) {
    if (!error) {
      const rbody = JSON.parse(body);
      console.log(rbody.name);
      idx++;
      charRequest(idx, characters[idx], characters, limit);
    } else {
      console.error('error:', error);
    }
  });
}
