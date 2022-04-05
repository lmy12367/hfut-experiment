// miniprogram/page/disable/disableMyAdress/disableMyAdress.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    adresses: [
      {id: '1', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大', checked: 'true'},
      {id: '2', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大'},
      {id: '3', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大'},
      {id: '4', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大'},
      {id: '5', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大'},
      {id: '6', name: '名媛', phone: '13012345678', adr_detail:'安徽省合肥市合工大'}
    ]
  },
  radioChange: function(e) {
    console.log('radio发生change事件，携带value值为：', e.detail.value)
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})