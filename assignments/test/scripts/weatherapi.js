var weatherRequest = new XMLHttpRequest();

var apiURLstring = 'https://api.openweathermap.org/data/2.5/weather?id=5604473&appid=05e096cdee24f552b3f8257736edcd2d&units=imperial';

weatherRequest.open('GET', apiURLstring, true);
weatherRequest.responseType = 'json';
weatherRequest.send();

weatherRequest.onload = function(){
    var weatherData = weatherRequest.response;
    document.getElementById("current-temp").innerHTML = weatherData.main.temp;
}