const express = require('express');
const app = express();

const log = require('morgan');
const path = require('path');

app.use(log ('dev') );

app.use( function (req, res, next){
	console.log('Richiesta verso ' + req.url + '(' + new Date() + ')');
	next();
});

app.use(
	'/js',
	express.static ( path.resolve( __dirname, 'js'))
);


app.get('/', function(req, res) {
  res.sendFile(
  		path.resolve( __dirname, 'html', 'basic.html')
  		);
});



app.listen(3000, function() {
    console.log('Server in ascolto sulla porta 3000 ...');
  });
