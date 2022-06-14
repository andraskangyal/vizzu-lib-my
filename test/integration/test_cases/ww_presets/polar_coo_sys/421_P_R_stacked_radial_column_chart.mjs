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
//               record.Country == 'Germany' ||
            record.Country == 'Denmark' || 
               record.Country == 'Estonia'
    }),
      config: {
        channels: {
          x: {attach: 'Country' },
          y: {attach: ['Joy factors', 'Value 2 (+)'] },
          color: {attach: 'Joy factors'},
//          label: {attach: 'Value 2 (+)'},
        },
        title: 'Stacked Radial Column Chart',
        coordSystem: 'polar'
      },
      style: {
          plot: {
              paddingLeft: 0,
              paddingRight: 150,
              yAxis: {
                  label: {
                     paddingRight: 0
                  }
              },
              xAxis: {
                  label: { paddingTop: 10 }
              }
          }
      }
    }
  ),
  chart => chart.feature('tooltip',true)
];

export default testSteps;