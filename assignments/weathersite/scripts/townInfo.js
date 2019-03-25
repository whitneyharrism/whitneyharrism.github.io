var townInfo = {
    "towns": [
        {
            "name": "Franklin",
            "motto": "Where you will grow!",
            "yearFounded": 1788,
            "currentPopulation": 30458,
            "averageRainfall": 21,
            "events": [
                "March 4: March to the Drum of Donuts",
                "September 5 - 11: Founder Days",
                "December 1 - 26: Christmas in the Heart"
            ]
        },
        {
            "name": "Fish Haven",
            "motto": "This is Fish Heaven.",
            "yearFounded": 1864,
            "currentPopulation": 501,
            "averageRainfall": 14.20,
            "events": [
                "April 1: How Big Was That Fish Day",
                "May 15-30: Rush the Creek Days",
                "July 24: Bear Lake Blunder Run",
                "December 12: Light the Tree"
            ]
        },
        {
            "name": "Greenville",
            "motto": "Green is our way of life.",
            "yearFounded": 1805,
            "currentPopulation": 33458,
            "averageRainfall": 25,
            "events": [
                "February 10-12: Greenbration",
                "May 8 - 18: Greenville Founder Days",
                "June 20: Verde and Valiant Day",
                "November 15-16: Greensome Gathering"
            ]
        },
        {
            "name": "Placerton",
            "motto": "Positive Placement in Placerton.",
            "yearFounded": 1946,
            "currentPopulation": 512,
            "averageRainfall": 39,
            "events": [
                "July 4: A Blaze of Glory",
                "October 20: Fall through Fall"
            ]
        },
        {
            "name": "Preston",
            "motto": "Home of Napoleon Dynamite",
            "yearFounded": 1866,
            "currentPopulation": 5204,
            "averageRainfall": 16.65,
            "events": [
                "March 29: Work Creek Revival",
                "July 8-12: Napoleon Dynamite Festival",
                "November 2-4: Freedom Days"
            ]
        },
        {
            "name": "Soda Springs",
            "motto": "Historic Oregon Trail Oasis. The Soda is on Us",
            "yearFounded": 1858,
            "currentPopulation": 2985,
            "averageRainfall": 15.75,
            "events": [
                "February 29: Geyser Song Day",
                "May 1-6: Days of May Celebration",
                "October 15-16: Octoberfest"
            ]
        },
        {
            "name": "Springfield",
            "motto": "Where everyone is lifted.",
            "yearFounded": 1826,
            "currentPopulation": 17852,
            "averageRainfall": 17,
            "events": [
                "January 8: Spring into Winter",
                "April 10-20: Celebration of Life",
                "July 31-Aug 15: Dog Days of Summer Festival"
            ]
        }
    ]
}

document.getElementById("prestonMotto").innerHTML = townInfo.towns[4].motto;
document.getElementById("prestonYear").innerHTML = townInfo.towns[4].yearFounded;
document.getElementById("prestonPop").innerHTML = townInfo.towns[4].currentPopulation;
document.getElementById("prestonRain").innerHTML = townInfo.towns[4].averageRainfall;
document.getElementById("prestonEvents1").innerHTML = townInfo.towns[4].events[0];
document.getElementById("prestonEvents2").innerHTML = townInfo.towns[4].events[1];

document.getElementById("sodaMotto").innerHTML = townInfo.towns[5].motto;
document.getElementById("sodaYear").innerHTML = townInfo.towns[5].yearFounded;
document.getElementById("sodaPop").innerHTML = townInfo.towns[5].currentPopulation;
document.getElementById("sodaRain").innerHTML = townInfo.towns[5].averageRainfall;
document.getElementById("sodaEvents1").innerHTML = townInfo.towns[5].events[0];
document.getElementById("sodaEvents2").innerHTML = townInfo.towns[5].events[1];

document.getElementById("fishMotto").innerHTML = townInfo.towns[1].motto;
document.getElementById("fishYear").innerHTML = townInfo.towns[1].yearFounded;
document.getElementById("fishPop").innerHTML = townInfo.towns[1].currentPopulation;
document.getElementById("fishRain").innerHTML = townInfo.towns[1].averageRainfall;
document.getElementById("fishEvents1").innerHTML = townInfo.towns[1].events[0];
document.getElementById("fishEvents2").innerHTML = townInfo.towns[1].events[1];

document.getElementById("prestonEvents3").innerHTML = townInfo.towns[4].events[2];
document.getElementById("sodaEvents3").innerHTML = townInfo.towns[5].events[2];
document.getElementById("fishEvents3").innerHTML = townInfo.towns[1].events[2];
document.getElementById("fishEvents4").innerHTML = townInfo.towns[1].events[3];