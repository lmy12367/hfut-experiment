// miniprogram/page/company/companyApplicationWork/companyApplicationWork.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    currentIndex: 0,
    "firstList": [{ title: '已申请成功，等待查阅', idtntity: '产品经理', time: '2021-8-4',local: '上海',name:'上海一家有限公司' },{ title: '已申请成功，等待查阅', idtntity: '产品经理', time: '2021-8-4',local: '上海',name:'上海一家有限公司' },{ title: '已申请成功，等待查阅', idtntity: '产品经理', time: '2021-8-4',local: '上海',name:'上海一家有限公司' }],
    "secondList": [{ title: '已申请成功，等待查阅', idtntity: '产品经理', time: '2021-8-4',local: '上海',name:'上海一家有限公司' }],
    "thirdList": [{ title: '已申请成功，等待查阅', idtntity: '产品经理', time: '2021-8-4',local: '上海',name:'上海一家有限公司' }],
  },
  //swiper切换时会调用
  pagechange: function (e) {
    if ("touch" === e.detail.source) {
      let currentPageIndex = this.data.currentIndex
      currentPageIndex = (currentPageIndex + 1) % 3
      this.setData({
        currentIndex: currentPageIndex
      })
    }
  },
  //用户点击tab时调用
  titleClick: function (e) {
    let currentPageIndex =
      this.setData({
        //拿到当前索引并动态改变
        currentIndex: e.currentTarget.dataset.idx
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