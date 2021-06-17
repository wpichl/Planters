document.addEventListener('DOMContentLoaded', (event) => {
    fetch('http://192.168.0.2/stats')
        .then(response => response.text())
        .then(data => {
            const chartdata = JSON.parse(data);
            new Chart("myChart", {
                type: "bar",
                data: {
                    labels: Object.keys(chartdata),
                    datasets: [{
                        data: Object.values(chartdata)
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
        });
});
