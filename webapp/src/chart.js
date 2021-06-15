var xValues = ["January", "February", "March", "April", "May", "June"];
var yValues = [30, 22, 26, 32, 11, 28];
var barColors = ["blue", "blue", "blue", "blue", "blue", "blue"];

var json = {
    "21-06-2021": 3,
    "21-07-2021": 4
};

new Chart("myChart", {
    type: "bar",
    data: {
        labels: xValues,
        datasets: [{
            backgroundColor: barColors,
            data: yValues
        }]
    },
    options: {
        legend: {display: false},
        title: {
            display: true,
            text: "Number of watering processes"
        }
    }
});
