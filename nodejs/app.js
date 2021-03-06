const express = require('express');
const app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);

const log = require('morgan');
const path = require('path');
const bodyParser =require('body-parser');

const mqtt = require('mqtt');
const client = mqtt.connect('mqtt://localhost:1883', {
	clean: true,
    	clientId: 'nodeJS'
	
	});



app.use( bodyParser.urlencoded( { extended: false } ) );

app.use(express.static(path.join(__dirname, 'html')));

app.use(log ('dev') );

app.use( function (req, res, next){
	console.log('Richiesta verso ' + req.url + '(' + new Date() + ')');
	next();
});

client.on('connect', () => {
  client.subscribe('direzione')
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

io.on('connection', function (socket) {
  console.log('pilota connesso');

  socket.on('coordinate', function (data) {
	console.log('coordinate ricevute ', 'x: ', data.x, 'y: ', data.y);

	client.on('connect', (connack) => {  
    	client.publish('direzione', 'ciao');
	});

	
  });	
    


});  

http.listen(3000, function() {
    console.log('Server in ascolto sulla porta 3000 ...');
  });
