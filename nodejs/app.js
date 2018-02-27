const express = require('express');
const app = express();
const io = require('socket.io');
const log = require('morgan');
const path = require('path');

app.use(log ('dev') );

app.use( function (rq, res, next){
	console.log('Richiesta verso ' + req.url + '(' + new Date() + ')');
	next();
});



app.get('/', function(req, res) {
  res.sendFile(__dirname, 'html', 'joy.html');
});


io.on('connection', function (socket) {
  console.log('richiesta di connessione dal client');
  console.log('invio tutte le temperature');

  });
});


app.listen(3000, function() {
    console.log('Server in ascolto sulla porta 3000 ...');
  });
