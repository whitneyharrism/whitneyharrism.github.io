var data = {
    "temples": [
        {
            "name": "Salt Lake Temple",
            "closings": [
                "Tuesday, 2 July 2019 - Monday, 15 July 2019",
                "Wednesday, 24 July 2019",
                "Saturday, 5 October 2019",
                "Wednesday, 27 November 2019 (Limited Hours)",
                "Thursday, 28 November 2019 - Friday, 29 November 2019",
                "Tuesday, 24 December 2019 - Wednesday, 25 December 2019",
                "Tuesday, 31 December 2019"
            ]
        },
        {
            "name": "Logan Temple",
            "closings": [
                "Thursday, 4 July 2019",
                "Monday, 22 July 2019 - Monday, 5 August 2019",
                "Saturday, 5 October 2019",
                "Wednesday, 27 November 2019 (Limited Hours)",
                "Thursday, 28 November 2019",
                "Tuesday, 24 December 2019 - Wednesday, 25 December 2019",
                "Tuesday, 31 December 2019 (Limited Hours)"
            ]
        },
        {
            "name": "Idaho Falls Temple",
            "closings": [
                "Monday, 24 June 2019 - Monday, 8 July 2019",
                "Saturday, 5 October 2019",
                "Wednesday, 27 November 2019 (Limited Hours)",
                "Thursday, 28 November 2019",
                "Tuesday, 24 December 2019 - Wednesday, 25 December 2019",
                "Tuesday, 31 December 2019 (Limited Hours)"
            ]
        },
        {
            "name": "San Diego Temple",
            "closings": [
                "Thursday, 4 July 2019",
                "Monday, 30 September 2019 - Monday, 11 November 2019",
                "Wednesday, 27 November 2019 - Thursday, 28 November 2019",
                "Tuesday, 24 December 2019 - Wednesday, 25 December 2019",
                "Tuesday, 31 December 2019"
            ]
        }
    ]
}

document.getElementById("date1").innerHTML = data.temples[0].closings[0];
document.getElementById("date2").innerHTML = data.temples[0].closings[1];
document.getElementById("date3").innerHTML = data.temples[0].closings[2];
document.getElementById("date4").innerHTML = data.temples[0].closings[3];
document.getElementById("date5").innerHTML = data.temples[0].closings[4];
document.getElementById("date6").innerHTML = data.temples[0].closings[5];
document.getElementById("date7").innerHTML = data.temples[0].closings[6];

