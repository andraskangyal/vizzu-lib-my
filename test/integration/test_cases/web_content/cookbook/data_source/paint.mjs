const testSteps = [
  (chart) => {
    const data = {
      series: [
        { name: 'index', type: 'dimension' },
        { name: 'x', type: 'measure' },
        { name: 'y', type: 'measure' }
      ]
    }

    let index = 0

    chart.on('click', (event) => {
      const convert = chart.getConverter('plot-area', 'canvas', 'relative')
      const rel = convert(event.detail.position)
      chart.animate(
        {
          data: {
            records: [[index++, rel.x, rel.y]]
          }
        },
        0.1
      )
    })

    return chart.animate({
      data,
      config: {
        x: { set: 'x', range: { min: 0, max: 1 } },
        y: { set: 'y', range: { min: 0, max: 1 } },
        geometry: 'circle',
        noop: 'index',
        title: 'Click the chart to put in data points!'
      }
    })
  },
  (chart) => {
    chart._cChart._call(chart._cChart._wasm._vizzu_pointerDown)(
      chart.render.ccanvas.getId(),
      0,
      100,
      100
    )
    chart._cChart._call(chart._cChart._wasm._vizzu_pointerUp)(
      chart.render.ccanvas.getId(),
      0,
      100,
      100
    )
    return chart.anim
  },
  (chart) => {
    chart._cChart._call(chart._cChart._wasm._vizzu_pointerDown)(
      chart.render.ccanvas.getId(),
      0,
      300,
      200
    )
    chart._cChart._call(chart._cChart._wasm._vizzu_pointerUp)(
      chart.render.ccanvas.getId(),
      0,
      300,
      200
    )
    return chart.anim
  }
]

export default testSteps
