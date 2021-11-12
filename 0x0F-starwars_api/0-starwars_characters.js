#!/usr/bin/node
// prints all characters of a Star Wars movie
const request = require('request');
request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (err, res, body) {
  if (err) throw err;
  const ch = JSON.parse(body).characters;
  charRes(ch, 0);
});

function charRes (url, index) {
  request(url[index], (err, res, body) => {
    if (!err) {
      console.log(JSON.parse(body).name);
      if (index + 1 < url.length) charRes(url, ++index);
    }
  });
}
