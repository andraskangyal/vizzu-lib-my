import { data } from '/test/integration/test_data/chart_precision.js';

const testSteps = [
  chart => chart.animate(
    {
      data: data,
      descriptor: {
        channels: {
          x: {attach: ['Parents']},
          y: {attach: ['Childs', 'Values parent'], range: '0,1.1,%'},
          label: { attach: ['Values parent']},
          size: { attach: ['Values parent']}
        },
        title: 'Chart Precision Circle',
        geometry: 'circle',
        legend: null
      }
    }
  )
];

export default testSteps;