var temp = 50;
var windspeed = 10;
var windchill = 35.74 + 06215*temp - 35.75*Math.pow(windspeed, 0.16) + 0.4275*temp*Math.pow(windspeed, 0.16);

document.getElementById("temp").innerHTML = temp + '&deg;';
document.getElementById("windspeed").innerHTML = windspeed + ' mph';
document.getElementById("windchill").innerHTML = windchill.toFixed(0) + '&deg;';