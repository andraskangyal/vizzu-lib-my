import { data } from '/test/integration/test_data/chart_types_eu.js';

const testSteps = [
    chart => chart.animate({
        data: data,
        config: {
            channels:
            {
                y: {
                    attach: ['Value 5 (+/-)'],
                    range: {
                        min: '-10%',
                        max: '110%'
                    }
                },
                x: { attach: ['Year'] },
                color: { attach: ['Country'] }
            },
            title: 'Line Chart',
            geometry: 'line'
        }
    })
];

export default testSteps;