var xValues = ["May", "June", "July", "August", "September"];
var yValues = [30, 22, 26, 32, 11];
var barColors = ["blue", "blue", "blue", "blue", "blue"];

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
