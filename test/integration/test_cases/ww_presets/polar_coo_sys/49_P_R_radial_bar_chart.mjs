import { data } from '../../../test_data/chart_types_eu.mjs';

const testSteps = [
    chart => chart.animate(
        {
            data: Object.assign(data, {
                filter: record =>
                    record.Country == 'Austria' ||
                    record.Country == 'Belgium' ||
                    record.Country == 'Bulgaria' ||
                    record.Country == 'Cyprus' ||
                    record.Country == 'Czechia' ||
                    record.Country == 'Denmark'
            }),
            config:
            {
                channels:
                {
                    y: { attach: 'Country', range:{min: '-50%'} },
                    x: { attach: 'Value 1 (+)' }
                },
                title: 'Radial Bar Chart',
                coordSystem: 'polar'
            },
            style: {
                plot: {
                    paddingLeft: '3.8em',
                    yAxis: {                
                        color: '#ffffff00',
                        title: { color: '#ffffff00' },
                        label: { paddingRight: '0.8em' },
                        ticks: { color: '#ffffff00' }
                    },
                    xAxis: {
                        title: { color: '#ffffff00' },
                        label: { color: '#ffffff00' },
                        interlacing: { color: '#ffffff00' },
                    }
                }
            }
        }
    ),
    chart => chart.feature('tooltip',true)
];

export default testSteps;