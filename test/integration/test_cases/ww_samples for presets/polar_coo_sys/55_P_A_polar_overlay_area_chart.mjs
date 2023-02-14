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
                   record.Country == 'Hungary'
            }),
            config: {
                channels: {
                    x: 'Year',
                    y: 'Value 2 (+)',
                    color: 'Country'
                },
                title: 'Polar Overlay Area Chart',
                geometry: 'area',
                coordSystem: 'polar',
            },
            style: {
                plot: {
                    marker: {
                        fillOpacity: 0.5,
                        borderWidth: 0}
                }
            }
        }
    ),
    chart => chart.feature('tooltip',true)
];

export default testSteps;