// miniprogram/page/company/companyReportList/companyReportList.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    work_type:{
      select: false,
      type_selected: '请选择',
      types: ['类型1', '类型2', '类型3'],
      select_me: "work_type"
    }
  },
  bindShowMsg_local() {
    let local = 'work_type.select'
    this.setData({
      [local]: !this.data.work_type.select,
    })
  },
  mySelect(e) {
    var name = e.currentTarget.dataset.name
    var which = e.currentTarget.dataset.which
    var change = which + '.' + 'type_selected'
    which = which + '.select'
    console.log(name)
    console.log(which)
    console.log(change)
    this.setData({
      [change]: name,
      [which]: false
    })
  },
  doPass(){
    wx.showToast({
      title: '操作成功',
      icon: 'success',
      duration: 500
    })
  },
  noPass(){
    wx.showToast({
      title: '操作成功',
      icon: 'success',
      duration: 500
    })
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