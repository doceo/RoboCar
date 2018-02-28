const express = require('express');
const app = express();

const log = require('morgan');
const path = require('path');

const bodyParser =require('body-parser');

app.use( bodyParser.urlencoded( { extended: false } ) );

app.use(log ('dev') );

app.use( function (req, res, next){
	console.log('Richiesta verso ' + req.url + '(' + new Date() + ')');
	next();
});


app.get('/', function(req, res) {
  res.sendFile(
  		path.resolve( __dirname, 'html', 'basic.html')
  		);
});

app.post('/coordinate', function(req, res) {
 	console.log(req.body);
 	res.end();

});


app.listen(3000, function() {
    console.log('Server in ascolto sulla porta 3000 ...');
  });
